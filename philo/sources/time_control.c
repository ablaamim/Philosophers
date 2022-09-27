/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:07:31 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/26 02:53:21 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

atomic_size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0x0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	my_sleep(t_table *table, size_t time_sleep)
{
	atomic_size_t	time;

	time = get_time();
	while (!(table->died))
	{
		if (get_time() - time >= time_sleep)
			break ;
		usleep(1000);
	}
}
