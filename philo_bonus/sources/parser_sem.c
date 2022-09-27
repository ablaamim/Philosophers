/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:09:29 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/26 02:34:11 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

void	ft_initialize_table_sem(t_table_sem *table)
{
	int	i;

	i = -1;
	table->all_eat = 0x0;
	table->died = 0x0;
	table->philos = (t_philo_sem *) malloc (sizeof(t_philo_sem) \
			* table->n_philos);
	while (++i < table->n_philos)
	{
		table->philos[i].enumerator = i + 1;
		table->philos[i].table = table;
		table->philos[i].eat_counter = 0x0;
		if (i + 1 == table->n_philos)
			table->philos[i].right_philo = &table->philos[0];
		else
			table->philos[i].right_philo = &table->philos[i + 1];
		if (i == 0x0)
			table->philos[i].left_philo = &table->philos[table->n_philos - 1];
		else
			table->philos[i].left_philo = &table->philos[i - 1];
	}
}

void	ft_initialize_sem(t_table_sem *table)
{
	sem_unlink("/sem_printer");
	sem_unlink("/sem_checker");
	sem_unlink("/sem_forks");
	table->forks = sem_open("/sem_forks", O_CREAT, 0644, table->n_philos);
	table->printer = sem_open("/sem_printer", O_CREAT, 0644, 0x1);
	table->checker = sem_open("/sem_checker", O_CREAT, 0644, 0x1);
	if (table->printer == SEM_FAILED || table->checker == SEM_FAILED \
			|| table->forks == SEM_FAILED)
	{
		write(2, ERROR_SEM, sizeof(ERROR_SEM));
		exit(EXIT_FAILURE);
	}
}

int	parser_sem(int argc, char **argv, t_table_sem *table)
{
	if (args_checker(argc, argv))
		return (EXIT_FAILURE);
	table->n_philos = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_slp = ft_atoi(argv[4]);
	table->n_times_eat = -1;
	if (argc == 6)
		table->n_times_eat = ft_atoi(argv[5]);
	ft_initialize_table_sem(table);
	ft_initialize_sem(table);
	return (EXIT_SUCCESS);
}
