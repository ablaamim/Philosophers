/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:53:05 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/13 21:23:45 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Parse input arguments, filter them and generate errors if the input is
 * invalid for the core program to process.
*/

void	philosophers_parser(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0x1;
	while (i < argc)
	{
		j = 0x1;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) || ft_atoi(argv[i]) < 0)
			{
				write(2, "Error\n", sizeof("Error\n"));
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	if (argc >= 7)
		write(2, "Error : Too many arguments\n", 
				sizeof("Error : Too many arguments\n"));
	else if (argc <= 4)
		write(2, "Error : Too few arguments\n", \
				sizeof("Error : Too few arguments\n"));
	else
		return ;
	exit (EXIT_FAILURE);
}
