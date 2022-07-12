/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:04:53 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/12 14:48:21 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

int	x = 2;

void	*routine()
{
	x++;
	sleep(2);
	printf("Process id : %d\nValue of x : %d\n", getpid(), x);
	return (0x0);
}

void	*routine2()
{
	sleep(2);
	printf("Process id : %d\nValue of x : %d\n", getpid(), x);
	return (0x0);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, 0x0, &routine, 0x0) != 0x0)
		return (EXIT_FAILURE);
	if (pthread_create(&t2, 0x0, &routine2, 0x0) != 0x0)
		return (EXIT_FAILURE);
	if (pthread_join(t1, 0x0) != 0x0)
		return (EXIT_FAILURE);
	if (pthread_join(t2, 0x0) != 0x0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
