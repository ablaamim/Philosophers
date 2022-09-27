/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:10:36 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/26 02:36:45 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Zero leaks and zero data race.
*/

int	err(void)
{
	write(2, "Error\n", sizeof("Error\n"));
	return (EXIT_FAILURE);
}

void	end_simulation(t_table *table, pthread_t *id)
{
	int	i;

	i = -1;
	while (++i < table->number_philos)
		pthread_join(id[i], 0x0);
	i = -1;
	while (++i < table->number_philos)
		pthread_mutex_destroy(&table->philos[i].fork);
	pthread_mutex_destroy(&table->printer);
	pthread_mutex_destroy(&table->checker);
	free(table->philos);
	free(id);
}

int	main(int argc, char **argv)
{
	pthread_t	*id;
	int			i;
	t_table		table;

	if ((argc < 5 || argc > 6) || parser(argc, argv, &table))
		return (err());
	id = (pthread_t *) malloc (table.number_philos * sizeof(pthread_t));
	table.time_init = get_time();
	i = -1;
	while (++i < table.number_philos)
	{
		if (pthread_create(&id[i], 0x0, &philo_lc, &table.philos[i]))
		{
			write(2, THRD_ERR, sizeof(THRD_ERR));
			free(table.philos);
			free(id);
			return (EXIT_FAILURE);
		}
		pthread_mutex_lock(&table.checker);
		table.philos[i].last_eat = table.time_init;
		pthread_mutex_unlock(&table.checker);
	}
	supervisor(&table);
	end_simulation(&table, id);
	return (EXIT_SUCCESS);
}
