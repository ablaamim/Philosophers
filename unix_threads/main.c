/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:28:51 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/05 18:44:36 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void	*routine()
{
	printf("Test from threads\n");
	sleep(3);
	printf("Ending thread\n");
	return (0x0);
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, 0x0, &routine, 0x0) != 0x0)
		return (0x1);
	if (pthread_create(&t2, 0x0, &routine, 0x0) != 0x0)
		return (0x1);
	pthread_join(t1, 0x0);
	pthread_join(t2, 0x0);
	return (EXIT_SUCCESS);
}
