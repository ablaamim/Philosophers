/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_failed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:47:26 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/11 15:40:50 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * simulation_failed : Free data and exit program.
*/

void	simulation_failed(int n, t_data *data, pthread_mutex_t *forks, \
		t_philo *philosophers)
{
	int	i;

	i = -1;
	while (++i < n && forks)
		pthread_mutex_destroy(&forks[i]);
	i = -1;
	while (++i < n)
	{
		if (philosophers[i].supper_locker)
			pthread_mutex_destroy(philosophers[i].supper_locker);
		if (philosophers[i].meals_locker)
			pthread_mutex_destroy(philosophers[i].meals_locker);
		free(philosophers[i].supper_locker);
		free(philosophers[i].meals_locker);
	}
	if (data->lock_printer)
		pthread_mutex_destroy(data->lock_printer);
	if (data->dinner_locker)
		pthread_mutex_destroy(data->dinner_locker);
	free(forks);
	free(philosophers);
	exit(EXIT_FAILURE);
}
