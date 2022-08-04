/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:03:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/04 17:20:12 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <ctype.h>
# include <string.h>
# include <stdbool.h>

# define MANY_ARGS "Error : Too many argumnents\n"
# define FEW_ARGS "Error : Too few arguments\n"

/*
 * Utils :
*/

bool	ft_isdigit(int c);
int		ft_atoi(char *str);

/*
 * Define CLASS PHILO :
*/

typedef struct s_data
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_data;

void	ft_parse_and_initialize(int argc, char **argv, t_data *data);

#endif
