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
            printf("%s\n", argv[i][j]);
            if (!ft_isdigit(argv[i][j]) || ft_atoi(argv[i]) == 0)
            {
                write(2, INVALID_ARGS, sizeof(INVALID_ARGS));
                exit(EXIT_FAILURE);
            }
        }
        if (argc > 6)
		    write(2, MANY_ARGS, sizeof(MANY_ARGS));
	    else if (argc < 5)
		    write(2, FEW_ARGS, sizeof(FEW_ARGS));
	    else
		    return ;
        exit(EXIT_FAILURE);
    }
}

void    ft_init_arguments(int argc, char **argv, t_data *data)
{
    ft_parser(argc, argv);
}