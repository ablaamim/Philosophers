/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:58:57 by ablaamim          #+#    #+#             */
/*   Updated: 2022/06/26 17:03:28 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Parse input and perform error handling.
*/

void	ft_parser(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0x0;
	while(++i < argc)
	{
		j = -1;
		while(argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) || ft_atol(argv[i]) <= 0 \
				|| ft_atol(argv[i]) > INT_MAX)
			{
				write(2, INVALID_ARGS, sizeof(INVALID_ARGS));
				exit(EXIT_FAILURE);
			}
		}
		if (argc > 6)
			write(2, MANY_ARGS, sizeof(MANY_ARGS));
		else if (argc < 5)
			write(2, FEW_ARGS, sizeof(FEW_ARGS));
		else
			return ;
		exit(EXIT_FAILURE);
	}
}

/*
 * Parse arguments.
 * Init arguments from input.

*/

void	ft_init_arguments(int argc, char **argv, t_data *data)
{
	ft_parser(argc, argv);
	data->number_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->n_times_each_philo_must_eat = -1;
	if (argc == 6)
		data->n_times_each_philo_must_eat = ft_atoi(argv[5]);
}
