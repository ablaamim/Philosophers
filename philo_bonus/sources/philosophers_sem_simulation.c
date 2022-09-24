/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_sem_simulation.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:00:28 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/22 15:54:45 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

int	process_constructor(pid_t *process, int (*f) (void *), t_sem_philo *philo)
{
	int	exit_code;

	exit_code = 0x0;
	*process = fork();
	if (*process == 0x0)
	{
		exit_code = f(philo);
		philosophers_exit(philo->data, philo->forks, philo->philos, exit_code);
	}
	return (exit_code);
}

int	joining_process(t_sem_philo *philos)
{
	int	exit_code;
	int	i;

	i = -1;
	exit_code = 0x0;
	while (++i < philos->data->number_of_philos && exit_code == 0x0)
	{
		waitpid(-1, &exit_code, 0x0);
		exit_code = WEXITSTATUS(exit_code);
	}
	if (exit_code)
	{
		i = -1;
		while (++i < philos->data->number_of_philos)
			kill(philos[i].process, SIGKILL);
	}
	return (exit_code);
}

int	philosophers_sem_simulation(int n_philos, t_sem_philo *philos)
{
	int	i;

	i = -1;
	philos->data->first_stamp = time_stamp();
	//printf("PHILO IS ALONE VAL = %d\n", philos->data->philo_is_alone);
	while (++i < n_philos)
	{
		//printf("Create processes\n");
		process_constructor(&philos[i].process, &ft_routine_sem, &philos[i]);
	}
	joining_process(philos);
	return (0x0);
}
