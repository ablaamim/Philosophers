/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 19:36:06 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/05 19:51:33 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int mails = 0x0;

void	*routine()
{
	int	i;

	i = 0x0;
	while (i < 10000000)
	{
		mails++;
		i++;
	}
	return (0x0);
}

int	main()
{
	pthread_t	t1;
	pthread_t	t2;

	pthread_create(&t1, 0x0, &routine, 0x0);
	pthread_create(&t2, 0x0, &routine, 0x0);
	pthread_join(t1, 0x0);
	pthread_join(t2, 0x0);
	printf("NUMBER OF MAILS : %d\n", mails);
	return (EXIT_SUCCESS);
}
