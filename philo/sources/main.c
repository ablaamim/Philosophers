/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:26:26 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/11 17:17:20 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Entry point of my program : main()
 * Init data and threads in order to start the simulation.
*/

/*
 * ft_parse_and_initialize : parse arguments and manage error handling,
 * in order to filter input entred by user, also it initializes data with
 * appropriate values from stdin input.
*/

void	end_simulation(int n, t_data *data, pthread_mutex_t *forks, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_mutex_destroy(&forks[i]);
	i = -1;
	while (++i < n && philos)
	{
		if (philos[i].supper_locker)
			pthread_mutex_destroy(philos[i].supper_locker);
		if (philos[i].meals_locker)
			pthread_mutex_destroy(philos[i].meals_locker);
		free(philos[i].supper_locker);
		free(philos[i].meals_locker);
	}
	if (data->lock_printer)
		pthread_mutex_destroy(data->lock_printer);
	if (data->dinner_locker)
		pthread_mutex_destroy(data->dinner_locker);
	free(data->lock_printer);
	free(data->dinner_locker);
	free(philos);
	free(forks);
}

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	*forks;
	t_philo			*philosophers;

	ft_parse_and_initialize(argc, argv, &data);
	initializer_of_data(&data, &forks,  &philosophers);
	initialize_forks(data.number_of_philos, &data, &forks, &philosophers);
	initialize_philosophers(data.number_of_philos, &data, &forks, &philosophers);
	
	philosophers_simulation(data.number_of_philos, philosophers);
	end_simulation(data.number_of_philos, &data, forks, philosophers);
	return (EXIT_SUCCESS);
}
