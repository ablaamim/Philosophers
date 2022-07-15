/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:30:04 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/13 21:39:41 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Entry point of my program.
 *
 * --> All core functions are called in here.
 */

int	main(int argc, char **argv)
 {
	t_data			data;
	pthread_mutex_t	*forks;
	t_philo		*philos;

	philosophers_parser(argc, argv);
	initialize_data(argc, argv, &data);
	initialize_forks(data.number_of_philosophers, &data, &forks, &philos);
	return (EXIT_SUCCESS);
}
