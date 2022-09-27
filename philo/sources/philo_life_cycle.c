/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:22:50 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/25 22:17:54 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Supervisor : check for death or if all philosophers have eaten all meals.
*/

void	supervisor(t_table *table)
{
	int	i;

	while (!table->all_eat)
	{
		i = -1;
		while (!table->died && ++i < table->number_philos)
		{
			pthread_mutex_lock(&table->checker);
			if (get_time() - table->philos[i].last_eat > (size_t) table->t_die)
			{
				actions_printer(&table->philos[i], DIE);
				table->died = 1;
			}
			pthread_mutex_unlock(&table->checker);
			usleep(100);
		}
		if (table->died)
			break ;
		i = 0x0;
		while (table->n_times_eat != -1 && i < table->number_philos && \
				table->philos[i].eat_counter >= table->n_times_eat)
			i++;
		if (i == table->number_philos)
			table->all_eat = 1;
	}
}

/*
 * Philosopher / thread must take forks/mutex/shared_memory and start eating.
*/

void	philo_go_eat(t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&philo->fork);
	actions_printer(philo, FORK);
	if (philo->table->number_philos == 1)
	{
		my_sleep(table, table->t_die);
		actions_printer(philo, DIE);
		pthread_mutex_unlock(&philo->fork);
		table->died = 1;
		return ;
	}
	pthread_mutex_lock(&philo->right_philo->fork);
	actions_printer(philo, FORK);
	pthread_mutex_lock(&table->checker);
	philo->eat_counter++;
	actions_printer(philo, EAT);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&table->checker);
	my_sleep(table, table->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right_philo->fork);
}

/*
 * Life cycle of each philosopher / thread.
*/

void	*philo_lc(void *ptr)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *) ptr;
	table = philo->table;
	if (philo->enumerator % 2 == 0x0)
		usleep(1000);
	while (!table->died && !table->all_eat)
	{
		philo_go_eat(philo);
		actions_printer(philo, SLEEP);
		my_sleep(table, table->time_to_sleep);
		actions_printer(philo, THINK);
		usleep(500);
	}
	return (0x0);
}
