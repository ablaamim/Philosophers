/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing_with_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:05:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/11 17:24:58 by ablaamim         ###   ########.fr       */
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
		printf("This thread is filthy\n");
		sleep(i);
		printf("Puts holly waters\n");
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
		printf("Processing a stupid process\n");
		printf("iterator position : %d\n", i);
		sleep(i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pthread_t	t1;

	if (pthread_create(&t1, 0x0, &multithreading, 0x0) != 0x0)
		return (0x0);
	stupid_process();
	if (pthread_join(t1, 0x0) != 0x0)
		return (0x0);
	return (EXIT_SUCCESS);
}
