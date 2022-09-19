/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine_sem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:11:45 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/17 22:13:10 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

void	philo_sem_go_eat_alone(t_sem_philo *philo)
{
	sem_wait(philo->fork_right);
	actions_sem_printer(philo, TOOK_FORK);
	sleeper(philo->data->time_to_die, philo);
}

void	philo_sema_go_eat(t_sem_philo *philo)
{
	sem_wait(philo->fork_right);
	sem_wait(philo->fork_left);
	actions_sem_printer(philo, TOOK_FORK);
	actions_sem_printer(philo, TOOK_FORK);
	actions_sem_printer(philo, IS_EATING);
	philo->last_supper = time_now(philo->data->first_stamp);
	sleeper(philo->data->time_to_eat, philo);
	sem_post(philo->fork_right);
	sem_post(philo->fork_left);
	philo->meals++;
}

void	philo_go_sleep(t_sem_philo *philo)
{
	actions_sem_printer(philo, IS_SLEEPING);
	sleeper(philo->data->time_to_sleep, philo);
}

int	ft_routine_sem(void *ptr)
{
	t_sem_philo	*philo;

	philo = (t_sem_philo *) philo;
	if (philo->enumerator % 2 == 0x0)
		my_sleep(5);
	if (philo->data->philo_is_alone)
		philo_sem_go_eat_alone(philo);
	while (1337)
	{
		philo_sema_go_eat(philo);
		if (philo->meals == philo->data->number_of_times_each_philosopher_must_eat)
			philosophers_exit(philo->data, philo->forks, philo->philos, EXIT_SUCCESS);
		philo_go_sleep(philo);
		philo_go_think(philo);
	}
	return (0x0);
}

