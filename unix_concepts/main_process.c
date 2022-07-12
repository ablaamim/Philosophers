/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_vs_thread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:02:52 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/12 14:42:02 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int	main(int argc, char **argv)
{
	int	pid;
	int	x;

	x = 0x1;
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0x0)
		++x;
	sleep(2);
	printf("x value = %d\n", x);
	printf("Processes id : %d\n", getpid());
	if (pid != 0x0)
		wait(0x0);
	return (EXIT_SUCCESS);
}
