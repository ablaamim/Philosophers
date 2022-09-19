/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_simulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 22:50:02 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/16 17:02:27 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	all_of_them_ate(t_philo *philos)
{
	int	i;
	int	had_his_dinner;

	had_his_dinner = 0x0;
	i = -1;
	while (++i < philos->data->number_of_philos)
	{
		if (meals_getter(&philos[i]) == \
				philos[i].data->number_of_times_each_philosopher_must_eat)
			had_his_dinner++;
	}
	if (had_his_dinner == philos->data->number_of_philos)
		return (0x1);
	return (0x0);
}

void	jesus_last_supper(t_philo *philo)
{
	pthread_mutex_lock(philo->data->dinner_locker);
	philo->data->dinner_over = 0x1;
	pthread_mutex_unlock(philo->data->dinner_locker);
}

int	last_supper_getter(t_philo *philo)
{
	long	last_supper;

	pthread_mutex_lock(philo->supper_locker);
	last_supper = philo->last_supper;
	pthread_mutex_unlock(philo->supper_locker);
	return (last_supper);
}

void	*philosophers_supervisor(void *ptr)
{
	int		i;
	long	time_current;
	long	time_to_die;
	t_philo	*philos;

	philos = (t_philo *) ptr;
	time_to_die = philos->data->time_to_die;
	while (!all_of_them_ate(philos))
	{
		i = -1;
		while (++i < philos->data->number_of_philos)
		{
			time_current = time_now(philos->data->first_stamp);
			if ((time_current - last_supper_getter(&philos[i])) >= time_to_die)
			{
				jesus_last_supper(&philos[i]);
				actions_printer(&philos[i], HAS_DIED);
				return (0x0);
			}
		}
		my_sleep(1);
	}
	return (0x0);
}

int	philosophers_simulation(int n, t_philo *philos)
{
	int			i;
	pthread_t	supervisor_thread;

	i = -1;
	philos->data->first_stamp = time_stamp();
	while (++i < n)
	{
		pthread_create(&philos[i].thread, 0x0, &routine, &philos[i]);
	}
	pthread_create(&supervisor_thread, 0x0, &philosophers_supervisor, philos);
	i = -1;
	while (++i < n)
		pthread_join(philos[i].thread, 0x0);
	pthread_join(supervisor_thread, 0x0);
	return (EXIT_SUCCESS);
}
