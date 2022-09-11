/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:03:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/11 16:59:44 by ablaamim         ###   ########.fr       */
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
# include <sys/time.h>

# define MANY_ARGS "Error : Too many argumnents\n"
# define FEW_ARGS "Error : Too few arguments\n"
# define MUTEX_ALLOC "Error : Failed to allocate mutex\n"
# define PHILO_ALLOC "Error : Failed to allocate philosophers\n"

# define TOOK_FORK 1
# define IS_EATING 2
# define IS_SLEEPING 3
# define IS_THINKING 4
# define HAS_DIED 4

/*
 * LIBFT UTILS :
*/

bool	ft_isdigit(int c);
int		ft_atoi(char *str);

/*
 *     //////////////// DEFINE DATA CLASS : /////////////////
 *
 * number_of_philos : how many philosophers are in simulation, also number of 
 * forks..
 * time_to_die : If a philosopher does not start eating the end of his first
 * meal or at the start of the simulation he dies.
 * time_to_eat : time that a philosopher takes to eat his meal.
 * time_to_sleep : implicit name :p
 * number_of_times_each_philosopher_must_eat : if all philos eat the number of
 * times precised by this argument, the simulation must end.
*/

typedef struct s_data
{
	int				dinner_over;
	int				philo_is_alone;
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			timestamp;
	pthread_mutex_t	*lock_printer;
	pthread_mutex_t	*dinner_locker;
}	t_data;

/*
 * ///////////////// DEFINE PHILOSOPHER  CLASS : //////////////////////
 *
 * This class defines philo attributes, it encapsulates t_data class.
 * t_philo.thread : Every philosopher is represented by a thread.
*/

typedef struct s_philo
{
	t_data			*data;
	int				meals;
	long			last_supper;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	int				enumerator;
	pthread_t		thread;
	pthread_mutex_t	*supper_locker;
	pthread_mutex_t	*meals_locker;
}	t_philo;

/*
 * PARSER / INITIALIZER.
*/

void	ft_parse_and_initialize(int argc, char **argv, t_data *data);
void	initializer_of_data(t_data *data, pthread_mutex_t **forks, t_philo \
		**philosophers);
void	initialize_forks(int n, t_data *data, pthread_mutex_t **forks, \
		t_philo **philosophers);
void	simulation_failed(int n_of_philos, t_data *data, pthread_mutex_t \
		*forks, t_philo *philosophers);
void	initialize_philosophers(int n_of_philos, t_data *data, pthread_mutex_t\
		**forks, t_philo **philosophers);

/*
 * SIMULATOR :
*/

int		philosophers_simulation(int n, t_philo *philos);
void	*routine(void *ptr);

/*
 * Timestamp control :
*/

void	my_sleep(int time_ms);
long	time_stamp(void);
long	time_now(long time_stamp);

/*
 * Actions :
*/

void	actions_printer(t_philo *philo, int action);
void	*philo_go_eat_alone(t_philo *philo);
void	philo_eat(t_philo *philo);
int		dinner_is_over(t_philo *philo);
int		last_supper_setter(t_philo *philo);
void	meals_setter(t_philo *philo);
int		meals_getter(t_philo *philo);
void	philo_go_sleep(t_philo *philo);

/*
 * SUPERVISOR :
*/

void	*philosophers_supervisor(void *ptr);
int		all_of_them_ate(t_philo *philo);

/*
 * END SIMULATION :
*/

void	end_simulation(int n, t_data *data, pthread_mutex_t *forks, t_philo *philos);

#endif
