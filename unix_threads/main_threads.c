/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:44:47 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/05 19:33:08 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int	x = 0x1;

void	*routine()
{
	x--;
	printf("Process ID : %d\n", getpid());
	printf("Value of x : %d\n", x);
	return (0x0);
}

void	*routine2()
{
	printf("Value of x : %d\n", x);
	return (0x0);
}

int	main()
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, 0x0, &routine, 0x0);
	pthread_join(t1, 0x0);
	pthread_create(&t2, 0x0, &routine2, 0x0);
	pthread_join(t2, 0x0);
	return (EXIT_SUCCESS);
}
