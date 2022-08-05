/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:03:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/08/05 17:03:47 by ablaamim         ###   ########.fr       */
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
# define MUTEX_ALLOC "Error : Failed to allocate mutex\n"

/*
 * UTILS :
*/

bool	ft_isdigit(int c);
int		ft_atoi(char *str);

/*
 * DEFINE CLASS DATA :
*/

typedef struct s_data
{
	int	philo_is_alone;
	int	number_of_philos;
	int	over;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_data;

/*
 * DEFINE CLASS PHILO :
*/

typedef struct s_philo
{
	pthread_t		thread;
	int				meals;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_data			*data;
}	t_philo;

/*
 * PARSER / INITIALIZER.
*/

void	ft_parse_and_initialize(int argc, char **argv, t_data *data);
void	initializer_of_data(t_data *data, pthread_mutex_t **forks, t_philo \
		**philosophers);
void	initialize_forks(int n, t_data *data, pthread_mutex_t **forks, \
		t_philo **philosophers);
void	simulation_failed(int n, t_data *data, pthread_mutex_t *forks, t_philo \
		*philosophers);

#endif
