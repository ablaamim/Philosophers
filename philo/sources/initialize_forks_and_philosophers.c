/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_forks_and_philosophers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:28:31 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/05 17:32:49 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * INITIALIZE PHILOSOPHERS :
*/

void	initialize_philosophers(int n_of_philos, t_data *data, pthread_mutex_t\
		**forks, t_philo **philosophers)
{
	int	i;

	i = -1;
	*philosophers = (t_philo *) malloc (sizeof(t_philo *) * n_of_philos);
	if (*philosophers == 0x0)
	{
		write(2, PHILO_ALLOC, sizeof(PHILO_ALLOC));
		simulation_failed(n_of_philos, data, *forks, *philosophers);
	}
	while (++i < n_of_philos)
	{
		(*philosophers)[i].data = data;
		(*philosophers)[i].meals = 0x0;
		(*philosophers)[i].fork_right = &(*forks)[i];
		(*philosophers)[i].fork_left = &(*forks)[i];
		(*philosophers)[i].enumerator = i + 1;
	}
	(*philosophers)[--i].fork_left = &(*forks)[0];
}
/*
 * INITIALIZE FORKS.
*/

void	initialize_forks(int n_of_philos, t_data *data, pthread_mutex_t \
		**forks, t_philo **philosophers)
{
	int	i;

	i = -1;
	*forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * n_of_philos);
	if (*forks == 0x0)
	{
		write(2, MUTEX_ALLOC, sizeof(MUTEX_ALLOC));
		simulation_failed(0x0, data, *forks, *philosophers);
	}
	i = -1;
	while (++i < n_of_philos)
		pthread_mutex_init(&(*forks)[i], 0x0);
}
