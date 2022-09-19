/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_failed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:48:11 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/17 21:53:59 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

void	simulation_failed_sem(t_sem_data *data, sem_t *forks, t_sem_philo *philos)
{
	sem_close(forks);
	sem_close(data->lock_print);
	sem_unlink("/forks");
	sem_unlink("/lock_print");
	free(philos);
}

void	philosophers_exit(t_sem_data *data, sem_t *forks, t_sem_philo *philos, int exit_code)
{
	sem_close(forks);
	sem_close(data->lock_print);
	sem_unlink("/forks");
	sem_unlink("/lock_print");
	free(philos);
	exit(exit_code);
}
