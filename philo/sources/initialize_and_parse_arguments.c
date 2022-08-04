/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_and_parse_arguments.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:06:51 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/04 19:06:58 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Parse arguments and error handling
*/

void	ft_parser(int argc, char **argv)
{
	int	i;
	int j;

	i = 0x1;
	j = 0x0;
	while (argv[i])
	{
		j = 0x0;
		if (!isdigit(argv[i][j++]) || ft_atoi(argv[i]) == 0x0)
		{
			write(2, "Error\n", sizeof("Error\n"));
			exit(EXIT_FAILURE);
		}
		printf("ARG[%d] => %s\n", i, argv[i]);
		i++;
	}
	if (argc > 6)
		write(2, MANY_ARGS, sizeof(MANY_ARGS));
	else if (argc <= 4)
		write(2, FEW_ARGS, sizeof(FEW_ARGS));
	else
		return ;
	exit(EXIT_FAILURE);
}

void	ft_parse_and_initialize(int argc, char **argv, t_data *data)
{
	ft_parser(argc, argv);
	data->number_of_philos = ft_atoi(argv[1]);
	printf("==> Number of philos : %d\n", data->number_of_philos);
	data->time_to_die = ft_atoi(argv[2]);
	printf("==> Time to die : %d\n", data->time_to_die);
	data->time_to_eat = ft_atoi(argv[3]);
	printf("==> Time to eat : %d\n", data->time_to_eat);
	data->time_to_sleep = ft_atoi(argv[4]);
	printf("==> Time to sleep : %d\n", data->time_to_sleep);
	data->number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
	{
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		printf("==> Nb of times each philo must eat : %d\n", data->number_of_times_each_philosopher_must_eat);
	}
}