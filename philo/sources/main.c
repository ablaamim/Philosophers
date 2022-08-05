/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:26:26 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/05 18:17:59 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Entry point of my program :
*/

/*
 * ft_parse_and_initialize : parse arguments and manage error handling,
 * in order to filter input entred by user, also it initializes data with
 * appropriate values from stdin input.
*/

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	*forks;
	t_philo			*philosophers;

	ft_parse_and_initialize(argc, argv, &data);
	initializer_of_data(&data, &forks,  &philosophers);
	initialize_forks(data.number_of_philos, &data, &forks, &philosophers);
	initialize_philosophers(data.number_of_philos, &data, &forks, \
			&philosophers);
	//philosphers_simulation(data.number_of_philos, philosophers);
	return (EXIT_SUCCESS);
}
