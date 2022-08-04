/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:03:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/04 15:30:02 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>

# define MANY_ARGS "Error : Too many argumnents\n"
# define FEW_ARGS "Error : Too few arguments\n"

int		main(int argc, char **argv);
void	ft_parse_and_initialize(int argc, char **argv);

/*
 * Utils :
*/

bool	ft_isdigit(int c);

#endif
