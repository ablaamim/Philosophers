/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_with_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:05:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/12 14:25:03 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	*multithreading()
{
	int	i;

	i = 0x0;
	while (i < 10)
	{
		printf("This thread is filthy, pid = %d\n", getpid());
		sleep(1);
		printf("iterator position : %d\n", i);
		i++;
	}
	return (0x0);
}

void	stupid_process(void)
{
	int	i;

	i = 0x0;
	while (i < 5)
	{
		printf("Processing a stupid process, pid = %d\n", getpid());
		printf("iterator position : %d\n", i);
		sleep(1);
		i++;
	}
}

void	retarded_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return ;
	printf("Retarded fork, pid = %d\n", getpid());
	if (pid != 0x0)
		wait(0x0);
}
int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;

	retarded_fork();
	if (pthread_create(&t1, 0x0, &multithreading, 0x0) != 0x0)
		return (EXIT_FAILURE);
	if (pthread_create(&t2, 0x0, &multithreading, 0x0) != 0x0)
		return (EXIT_FAILURE);
	stupid_process();
	if (pthread_join(t1, 0x0) != 0x0) //Wait for threads
		return (EXIT_FAILURE);
	if (pthread_join(t2, 0x0) != 0x0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
