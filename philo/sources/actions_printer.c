/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:38:33 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/25 21:00:12 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Retireve appropriate message
*/

char	*retrieve_message(int action)
{
	if (action == FORK)
		return (" Has taken a fork");
	if (action == EAT)
		return (" Is eating ");
	if (action == SLEEP)
		return (" Is sleeping");
	if (action == THINK)
		return (" Is thinking");
	if (action == DIE)
		return (" Died");
	return ("invalid action");
}

/*
 * print philosopher's status/action.
*/

void	actions_printer(t_philo *philo, int action)
{
	size_t	time;

	pthread_mutex_lock(&philo->table->printer);
	time = get_time() - philo->table->time_init;
	if (!philo->table->died && !philo->table->all_eat)
	{
		printf("%6ld ms", time);
		printf("%3d", philo->enumerator);
		printf("%s", retrieve_message(action));
		if (action == EAT)
			printf(" # %d", philo->eat_counter);
		printf("\n");
	}
	pthread_mutex_unlock(&philo->table->printer);
}
