/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:06:47 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/17 21:56:58 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_sem_data	data;
	sem_t	*forks;
	t_sem_philo	*philosophers;

	ft_parse_and_initialize_sem(argc, argv, &data);
	sema_forks_initializer(data.number_of_philos, &data, &forks, &philosophers);
	sema_philos_initializer(data.number_of_philos, &data, &forks, &philosophers);
	philosophers_sem_simulator(data.number_of_philos, philosophers);
	return (EXIT_SUCCESS);
}
