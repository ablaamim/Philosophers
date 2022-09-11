/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:55:16 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/11 21:34:40 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(philo->fork_left);
	if (dinner_is_over(philo))
	{
		pthread_mutex_unlock(philo->fork_right);
		pthread_mutex_unlock(philo->fork_left);
		return ;
	}
	actions_printer(philo, TOOK_FORK);
	actions_printer(philo, TOOK_FORK);
	actions_printer(philo, IS_EATING);
	last_supper_setter(philo);
	my_sleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	meals_setter(philo);
}

void	philo_go_sleep(t_philo *philo)
{
	actions_printer(philo, IS_SLEEPING);
	my_sleep(philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	actions_printer(philo, IS_THINKING);
	usleep(500);
}

void	*philo_go_eat_alone(t_philo *philo)
{
	//printf("==> GO EAT ALONE !\n");
	pthread_mutex_lock(philo->fork_right);
	actions_printer(philo, TOOK_FORK);
	pthread_mutex_unlock(philo->fork_right);
	return (0x0);
}

void	*routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *) ptr;
	if (philo->enumerator % 2)
		my_sleep(5);
	if (philo->data->philo_is_alone)
	{
		//printf("==> PHILO IS ALONE\n");
		return (philo_go_eat_alone(philo));
	}
	while (!dinner_is_over(philo))
	{
		philo_eat(philo);
		if (meals_getter(philo)== philo->data->number_of_times_each_philosopher_must_eat)
			return (0x0);
		philo_go_sleep(philo);
		philo_think(philo);
	}
	return (0x0);
}
