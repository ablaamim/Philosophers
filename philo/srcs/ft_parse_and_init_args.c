/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:58:57 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/31 15:00:27 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void    ft_parser(int argc, char **argv)
{
    int i;
    int j;

    i = 0x0;
    while(++i < argc)
    {
        j = -1;
        while(argv[i][++j])
        {
            if (!ft_isdigit(argv[i][j]))
            {
                write(2, "Error\n", sizeof("Error\n"));
                exit(EXIT_FAILURE);
            }
        }
        if (argc > 6)
		    write(2, "Too many args\n", sizeof("Too many args\n"));
	    else if (argc < 5)
		    write(2, "Too few args\n", sizeof("Too few args\n"));
	    else
		    return ;
        exit(EXIT_FAILURE);
    }
}

void    ft_init_arguments(int argc, char **argv, t_data *data)
{
    ft_parser(argc, argv);
}