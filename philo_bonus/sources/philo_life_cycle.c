/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 00:32:50 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/26 02:55:14 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

void	my_sleep_sem(t_table_sem *table, size_t time_slp)
{
	atomic_size_t	time;

	time = get_time();
	while (!(table->died))
	{
		if (get_time() - time >= time_slp)
			break ;
		usleep(100);
	}
}

/*
 * take forks and eat :
*/

void	philo_go_eat_sem(t_philo_sem *philo)
{
	t_table_sem	*table;

	table = philo->table;
	sem_wait(philo->table->forks);
	actions_printer_sem(philo, FORK_SEM);
	if (philo->table->n_philos == 1)
	{
		my_sleep_sem(table, table->time_die);
		actions_printer_sem(philo, DIE_SEM);
		table->died = 1;
		return ;
	}
	sem_wait(philo->table->forks);
	actions_printer_sem(philo, FORK_SEM);
	sem_wait(philo->table->checker);
	philo->eat_counter++;
	actions_printer_sem(philo, EAT_SEM);
	philo->last_eat = get_time();
	sem_post(philo->table->checker);
	my_sleep_sem(table, table->time_eat);
	sem_post(philo->table->forks);
	sem_post(philo->table->forks);
}

/*
 * Supervisor sem : check death and if all meals are eaten.
*/

void	*supervisor_sem(void *ptr)
{
	t_philo_sem	*philo;
	t_table_sem	*table;

	philo = (t_philo_sem *) ptr;
	table = philo->table;
	while (1)
	{
		sem_wait(table->checker);
		if (get_time() - philo->last_eat > (size_t) table->time_die)
		{
			actions_printer_sem(philo, DIE_SEM);
			sem_wait(table->printer);
			table->died = 1;
			exit (EXIT_DEAD);
		}
		sem_post(table->checker);
		if (table->died)
			break ;
		usleep(1000);
		if (table->n_times_eat != -1 && \
				philo->eat_counter >= table->n_times_eat)
			break ;
	}
	return (0x0);
}

/*
 * Life cycle of a philosopher :
*/

void	*philo_lc(void *ptr)
{
	t_philo_sem	*philo;
	t_table_sem	*table;

	philo = (t_philo_sem *) ptr;
	table = philo->table;
	philo->last_eat = table->time_init;
	pthread_create(&philo->death_checker, 0x0, supervisor_sem, (void *) philo);
	if (philo->enumerator % 2 == 0x0)
		usleep(1000);
	while (!table->died)
	{
		philo_go_eat_sem(philo);
		if (table->n_times_eat != -1 && philo->eat_counter == \
				table->n_times_eat)
			break ;
		actions_printer_sem(philo, SLEEP_SEM);
		my_sleep_sem(table, table->time_slp);
		actions_printer_sem(philo, THINK_SEM);
	}
	pthread_join(philo->death_checker, 0x0);
	exit(EXIT_ALIVE);
}
