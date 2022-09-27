/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 00:55:23 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/26 02:32:31 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers_bonus.h"
#include "../../philo/includes/philosophers.h"

/*
 * retrieve message string to print :
*/

char	*retrieve_message_sem(int action)
{
	if (action == FORK_SEM)
		return (" Has taken a fork");
	if (action == EAT_SEM)
		return (" Is eating");
	if (action == SLEEP_SEM)
		return (" Is sleeping");
	if (action == THINK_SEM)
		return (" Is thinking");
	if (action == DIE_SEM)
		return (" Died");
	return ("Error : Invalid message");
}

/*
 * Print philo status message :
*/

void	actions_printer_sem(t_philo_sem *philo, int action)
{
	size_t	time;

	time = get_time() - philo->table->time_init;
	sem_wait(philo->table->printer);
	if (!philo->table->died && !philo->table->all_eat)
	{
		printf("%6ld ms", time);
		printf("%3d", philo->enumerator);
		printf("%s", retrieve_message_sem(action));
		if (action == EAT_SEM)
			printf(" #%d", philo->eat_counter);
		printf("\n");
	}
	sem_post(philo->table->printer);
}
