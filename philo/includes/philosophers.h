/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:28:03 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/15 15:56:00 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>

/*
 * Each philosopher state.
*/

# define HAS_TAKEN_A_FORK 1
# define IS_EATING 2
# define IS_SLEEPING 3
# define IS_THINKING 4
# define DIED 5

typedef struct s_data
{
	int	philo_is_alone;
	int	number_of_philosophers;
	int	dinner_is_over;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_data;

typedef struct s_philo
{
	int			name;
	int			meals;
	long		last_meal;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*lock_meal;
	pthread_mutex_t	*lock_meals;
}	t_philo;

/*
 * Entry point of my program.
 * Core functions defining the algos.
*/

int		main(int argc, char **argv);
void	philosophers_parser(int argc, char **argv);

/*
 * Parser utils :
*/

int	ft_isdigit(int c);
int	ft_atoi(char *str);

/*
 * Init data :
*/

void	initialize_data(int argc, char **argv, t_data *data);

#endif
