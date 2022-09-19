/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_forks_and_philosophers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:28:31 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/16 17:01:10 by ablaamim         ###   ########.fr       */
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

	*philosophers = (t_philo *) malloc (sizeof(t_philo) * n_of_philos);
	if (*philosophers == 0x0)
	{
		write(2, PHILO_ALLOC, sizeof(PHILO_ALLOC));
		simulation_failed(n_of_philos, data, *forks, *philosophers);
	}
	i = -1;
	while (++i < n_of_philos)
	{
		(*philosophers)[i].data = data;
		(*philosophers)[i].meals = 0x0;
		(*philosophers)[i].fork_right = &(*forks)[i];
		(*philosophers)[i].fork_left = &(*forks)[i + 1];
		(*philosophers)[i].enumerator = i + 1;
		(*philosophers)[i].last_supper = 0x0;
		(*philosophers)[i].supper_locker = (pthread_mutex_t *) \
										malloc(sizeof(pthread_mutex_t) * 0x1);
		(*philosophers)[i].meals_locker = (pthread_mutex_t *) \
										malloc(sizeof(pthread_mutex_t) * 0x1);
		pthread_mutex_init((*philosophers)[i].supper_locker, 0x0);
		pthread_mutex_init((*philosophers)[i].meals_locker, 0x0);
	}
	(*philosophers)[--i].fork_left = &(*forks)[0];
}
/*
 * INITIALIZE FORKS.
 * Number of forks is equal to number of philosophers.
 * forks = mutex / shared memory..
 * philosphers = threads.
*/

void	initialize_forks(int n_of_philos, t_data *data, pthread_mutex_t \
		**forks, t_philo **philosophers)
{
	int	i;

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
