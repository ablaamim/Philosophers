/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:18:50 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/22 16:04:51 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

void	sleeper(int time_ms, t_sem_philo *philo)
{
	long	current_time;
	long	start_time;

	start_time = time_stamp();
	while ((time_stamp() - start_time) < (long) time_ms)
	{
		usleep(10);
		current_time = time_now(philo->data->first_stamp);
		if ((current_time - philo->last_supper) > philo->data->time_to_die)
		{
			actions_sem_printer(philo, HAS_DIED);
			philosophers_exit(philo->data, philo->forks, philo->philos, EXIT_FAILURE);
		}
	}
	if (philo->data->philo_is_alone)
	{
		// ACTIONS
		my_sleep(1);
		actions_sem_printer(philo, HAS_DIED);
		philosophers_exit(philo->data, philo->forks, philo->philos, EXIT_FAILURE);
		//exit(1); // REPL;
	}
}

void	philo_sem_try_wait(t_sem_philo *philo)
{
	long	current_time;

	while(*(int*) philo->forks < 2)
	{
		current_time = time_now(philo->data->first_stamp);
		if ((current_time - philo->last_supper) > philo->data->time_to_die)
		{
			actions_sem_printer(philo, HAS_DIED);
			philosophers_exit(philo->data, philo->forks, philo->philos, EXIT_FAILURE);
		}
		usleep(10);
	}
}
