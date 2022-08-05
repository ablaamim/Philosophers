/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_forks_and_philosophers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:28:31 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/05 17:06:32 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * INITIALIZE FORKS.
*/

void	initialize_forks(int n, t_data *data, pthread_mutex_t **forks,  \
		t_philo **philosophers)
{
	int	i;

	i = -1;
	*forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * n);
	if (*forks == 0x0)
	{
		write(2, MUTEX_ALLOC, sizeof(MUTEX_ALLOC));
		simulation_failed(0x0, data, *forks, *philosophers);
	}
	i = -1;
	while (++i < n)
		pthread_mutex_init(&(*forks)[i], 0x0);
}
