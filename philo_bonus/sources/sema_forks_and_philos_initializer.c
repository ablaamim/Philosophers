/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sema_forks_and_philos_initializer.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:17:50 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/17 21:58:04 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"

void	sema_forks_initializer(int n_philos, t_sem_data *data, sem_t **forks, t_sem_philo **philos)
{
	*forks = sem_open("/forks", O_CREAT, 0777, n_philos);
	if (*forks == 0x0)
	{
		printf("System failed to create semaphore\n");
		//exit(EXIT_FAILURE); // TO RL !!!!
		philosophers_exit(data, *forks, *philos, EXIT_FAILURE);
	}
}

void	sema_philos_initializer(int n_philos, t_sem_data *data, sem_t **forks, t_sem_philo **philos)
{
	int	i;

	*philos = (t_sem_philo *) malloc(sizeof(t_sem_philo) * n_philos);
	if (*philos == 0x0)
	{
		printf("System failed to allocate philosophers\n");
		//exit (EXIT_FAILURE);
		philosophers_exit(data, *forks, *philos, EXIT_FAILURE);
	}
	i = -1;
	while (++i < n_philos)
	{
		(*philos)[i].fork_right = *forks;
		(*philos)[i].fork_left = *forks;
		(*philos)[i].enumerator = i + 1;
		(*philos)[i].meals = 0x0;
		(*philos[i]).last_supper = 0x0;
		(*philos)[i].data = data;
		(*philos)[i].philos = *philos;
	}
}
