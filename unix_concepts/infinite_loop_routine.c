/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:10:51 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/11 16:13:48 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*myturn(void *arg)
{
	while (1337)
	{
		sleep(0x1);
		printf("My turn\n");
	}
	return (0x0);
}

void	yourturn(void)
{
	while (1337)
	{
		sleep(2);
		printf("Your turn\n");
	}
}

int	main(int argc, char **argv)
{
	pthread_t	newthread;

	pthread_create(&newthread, 0x0, myturn, 0x0);
	yourturn();
	return (EXIT_SUCCESS);
}
