/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_and_initialize.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:03:22 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/17 21:54:52 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

void	initializer_of_data_sem(t_sem_data *data, sem_t **forks, t_sem_philo **philos)
{
	*forks = 0x0;
	*philos = 0x0;
	if (data->number_of_philos == 0x1)
		data->philo_is_alone = 0x1;
	else
		data->philo_is_alone = 0x0;
	data->first_stamp = 0x0;
	data->lock_print = 0x0;
	data->lock_print = sem_open("/lock_print", O_CREAT, 0777, 0x1);
	if (data->lock_print == 0x0)
	{
		printf("System enable to create a semaphore\n");
		//exit(EXIT_FAILURE); //MUST BE REPLACED
		philosophers_exit(data, *forks, *philos, EXIT_FAILURE);
	}
}

void	ft_parse_sem(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0x0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) || ft_atoi(argv[i]) == 0x0)
			{
				write(2, "Error\n", sizeof("Error\n"));
				exit (EXIT_FAILURE);
			}
		}
	}
	if (argc > 6)
		write(2, MANY_ARGS, sizeof(MANY_ARGS));
	else if (argc <= 4)
		write(2, FEW_ARGS, sizeof(FEW_ARGS));
	else
		return ;
	exit(EXIT_SUCCESS);
}

/*
 * PARSE AND INITIALIZE DATA FROM USER INPUT.
*/

void	ft_parse_and_initialize_sem(int argc, char **argv, t_sem_data *data)
{
	ft_parse_sem(argc, argv);
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}
