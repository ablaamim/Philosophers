/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 23:03:38 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/27 17:02:47 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

int	err_sem(void)
{
	write(2, "Error\n", sizeof("Error\n"));
	exit(EXIT_FAILURE);
}

void	exit_philo_sem(t_table_sem *table)
{
	int	i;
	int	status;

	i = -1;
	while (++i < table->n_philos)
	{
		waitpid(-1, &status, 0x0);
		if (WEXITSTATUS(status) == EXIT_DEAD)
		{
			i = -1;
			while (++i < table->n_philos)
				kill(table->philos[i].process, SIGTERM);
			break ;
		}
	}
	sem_close(table->printer);
	sem_close(table->checker);
	sem_close(table->forks);
	sem_unlink("/sem_printer");
	sem_unlink("/sem_checker");
	sem_unlink("/sem_forks");
	free(table->philos);
}

int	main(int argc, char **argv)
{
	int			i;
	t_table_sem	table;

	if (argc < 5 || argc > 6 || parser_sem(argc, argv, &table))
		return (err_sem());
	table.time_init = get_time();
	i = -1;
	while (++i < table.n_philos)
	{
		table.philos[i].process = fork();
		if (table.philos[i].process == -1)
		{
			write(2, FORK_FAILED, sizeof(FORK_FAILED));
			exit (EXIT_FAILURE);
		}
		if (table.philos[i].process == 0x0)
			philo_lc((void *) &table.philos[i]);
	}
	exit_philo_sem(&table);
	return (EXIT_SUCCESS);
}
