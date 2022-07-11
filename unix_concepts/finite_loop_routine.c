/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finite_loop_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:43:53 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/11 16:42:01 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*myturn(void *arg)
{
	int	i;

	i = 0x0;
	while(i < 8)
	{
		sleep(1);
		printf("My turn %d\n", i);
		i++;
	}
	return (0x0);
}

void	your_turn(void)
{
	int	i;

	i = 0x0;
	while (i < 3)
	{
		sleep(1);
		printf("Your turn %d\n", i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pthread_t	new_thread;

	pthread_create(&new_thread, 0x0, myturn, 0x0);
	your_turn();
	pthread_join(new_thread, 0x0);
	return (EXIT_SUCCESS);
}
