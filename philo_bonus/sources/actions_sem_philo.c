/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_sem_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:25:23 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/17 21:39:56 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

void	actions_sem_printer(t_sem_philo *philo, int action)
{
	long	current_time;

	sem_wait(philo->data->lock_print);
	current_time = time_now(philo->data->first_stamp);
	if (action == TOOK_FORK)
		printf("%5ld %3d has taken a fork\n", current_time, philo->enumerator);
	else if (action == IS_EATING)
		printf("%5ld %3d is eating\n", current_time, philo->enumerator);
	else if (action == IS_SLEEPING)
		printf("%5ld %3d is sleeping\n", current_time, philo->enumerator);
	else if (action == IS_THINKING)
		printf("%5ld %3d is thinking\n", current_time, philo->enumerator);
	else if (action == HAS_DIED)
		printf("%5ld %3d died\n", current_time, philo->enumerator);
	if (action != HAS_DIED)
		sem_post(philo->data->lock_print);
}
