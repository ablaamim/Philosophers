/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:45:39 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/05 19:36:39 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int		main()
{
	int	pid;
	int	x;

	x = 0x1;
	pid = fork();
	if (pid == 0x0)
		x++;
	sleep(0x1);
	if (pid == -1)
		return (0x1);
	printf("PROCESS ID : %d\n", getpid());
	printf("Value of x is : %d\n", x);
	if (pid != 0x0)
		wait(0x0);
	return (EXIT_SUCCESS);
}
