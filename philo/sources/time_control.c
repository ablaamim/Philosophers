/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:09:12 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/11 17:15:54 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	my_sleep(int time_ms)
{
	long	t0;

	t0 = time_stamp();
	while ((time_stamp() - t0) < (long) time_ms)
		usleep(10);
}

long	time_stamp(void)
{
	struct timeval	time;

	gettimeofday(&time, 0x0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	time_now(long first_timestamp)
{
	return (time_stamp() - first_timestamp);
}
