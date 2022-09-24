/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:06:47 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/22 15:43:46 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_sem_data	data;
	sem_t		*forks;
	t_sem_philo	*philosophers;

	ft_parse_and_initialize_sem(argc, argv, &data);
	initializer_of_data_sem(&data, &forks, &philosophers);
	sema_forks_initializer(data.number_of_philos, &data, &forks, &philosophers);
	sema_philos_initializer(data.number_of_philos, &data, &forks, &philosophers);
	philosophers_sem_simulation(data.number_of_philos, philosophers);
	simulation_sema_end(&data, forks, philosophers);
	return (EXIT_SUCCESS);
}
