/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:11:57 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/13 21:46:17 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Initialize data with arguments input values in the given order.
*/

void	initialize_data(int argc, char **argv, t_data *data)
{
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (data->number_of_philosophers == 0)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}

void	initialize_philosophers(int n, t_data *data, pthread_mutex_t **forks, t_philo *philos)
{
	int	i;

	*forks = malloc (sizeof (pthread_mutex_t *) * n);
}
