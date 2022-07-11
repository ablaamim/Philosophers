/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:47:12 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/11 17:15:24 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void	*routine()
{
	printf("Test from threads\n");
	sleep(2);
	printf("Ending thread\n");
	return (0x0);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, 0x0, &routine, 0x0) != 0x0)
		return (EXIT_FAILURE);
	if (pthread_create(&t2, 0x0, &routine, 0x0) != 0x0)
		return (EXIT_FAILURE);
	if (pthread_join(t1, 0x0) != 0x0)
		return (EXIT_FAILURE);
	if (pthread_join(t2, 0x0) != 0x0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
