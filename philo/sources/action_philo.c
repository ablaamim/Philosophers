/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:03:38 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/11 21:36:04 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	meals_getter(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(philo->meals_locker);
	meals = philo->meals;
	pthread_mutex_unlock(philo->meals_locker);
	return (meals);
}

void	meals_setter(t_philo *philo)
{
	pthread_mutex_lock(philo->meals_locker);
	philo->meals++;
	pthread_mutex_unlock(philo->meals_locker);
}

void	last_supper_setter(t_philo *philo)
{
	//long	last_supper;

	pthread_mutex_lock(philo->supper_locker);
	philo->last_supper = time_now(philo->data->first_stamp);
	pthread_mutex_unlock(philo->supper_locker);
	//return (last_supper);
}

int	dinner_is_over(t_philo *philo)
{
	int	dinner_over;;

	pthread_mutex_lock(philo->data->dinner_locker);
	dinner_over = 0x0;
	if (philo->data->dinner_over)
		dinner_over = philo->data->dinner_over;
	pthread_mutex_unlock(philo->data->dinner_locker);
	return (dinner_over);
}

void	actions_printer(t_philo *philo, int action)
{
	long	time_current;

	//printf("PRINTER\n\n");
	pthread_mutex_lock(philo->data->lock_printer);
	time_current = time_now(philo->data->first_stamp);
	//printf("%5ld\n", philo->data->first_stamp);
	if (action == TOOK_FORK && !dinner_is_over(philo))
		printf("%5ld %3d Has taken a fork\n", time_current, philo->enumerator);
	else if (action == IS_EATING && !dinner_is_over(philo))
		printf("%5ld %3d Is eating\n", time_current, philo->enumerator);
	else if (action == IS_SLEEPING && !dinner_is_over(philo))
		printf("%5ld %3d Is sleeping\n", time_current, philo->enumerator);
	else if (action == IS_THINKING && !dinner_is_over(philo))
		printf("%5ld %3d Is thinking\n", time_current, philo->enumerator);
	else if (action == HAS_DIED)
		printf("%5ld %3d Died\n", time_current, philo->enumerator);
	pthread_mutex_unlock(philo->data->lock_printer);
}
