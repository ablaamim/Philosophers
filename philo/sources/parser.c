/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:30:19 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/25 22:17:29 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Check if arg is an int :
*/

int	int_validator(char *argv)
{
	size_t	len;

	len = ft_strlen(argv);
	if (*argv == '-' && *argv == '+')
		len--;
	if (*argv == '0')
		return (EXIT_FAILURE);
	while (*argv && len--)
		argv++;
	if (len > 10)
		return (EXIT_FAILURE);
	else if (len < 10)
		return (EXIT_SUCCESS);
	if (ft_strncmp(argv, "2147483648", 10) >= 0x0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
 * Number validator :
 * check if argv countains only digits.
*/

int	number_validator(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0x0;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '-')
			return (EXIT_FAILURE);
		else if (argv[i][0] == '+')
			j++;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

/*
 * Error handling of input arguments :
*/

int	args_checker(int argc, char **argv)
{
	int	i;

	i = 0x0;
	if (number_validator(argc, argv))
		return (EXIT_FAILURE);
	while (++i < argc)
	{
		if (int_validator(argv[i]))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_initialize_tab(t_table *table)
{
	int	i;

	i = -1;
	table->all_eat = 0x0;
	table->died = 0x0;
	table->philos = (t_philo *) malloc (sizeof(t_philo) * \
			table->number_philos);
	while (++i < table->number_philos)
	{
		table->philos[i].enumerator = i + 1;
		table->philos[i].table = table;
		table->philos[i].eat_counter = 0x0;
		if (i + 1 == table->number_philos)
			table->philos[i].right_philo = &table->philos[0];
		else
			table->philos[i].right_philo = &table->philos[i + 1];
		if (i == 0x0)
			table->philos[i].left_philo = \
				&table->philos[table->number_philos - 1];
		else
			table->philos[i].left_philo = &table->philos[i - 1];
		pthread_mutex_init(&table->philos[i].fork, 0x0);
	}
	pthread_mutex_init(&table->printer, 0x0);
	pthread_mutex_init(&table->checker, 0x0);
}

int	parser(int argc, char **argv, t_table *table)
{
	if (args_checker(argc, argv))
		return (EXIT_FAILURE);
	table->number_philos = ft_atoi(argv[1]);
	table->t_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->n_times_eat = -1;
	if (argc == 6)
		table->n_times_eat = ft_atoi(argv[5]);
	ft_initialize_tab(table);
	return (EXIT_SUCCESS);
}
