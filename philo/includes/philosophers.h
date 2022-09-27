/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:56:06 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/26 03:00:45 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdatomic.h>

/*
 * Error defines :
*/

# define THRD_ERR "Error : System enable to create thread\n"

/*
 * Message type class :
*/

enum e_message
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

/*
enum e_philo
{
	right_philo,
	left_philo
};
*/

/*
 * Philosopher class : Private
*/

typedef struct s_philo
{
	int				enumerator;
	atomic_int		eat_counter;
	atomic_size_t	last_eat;
	pthread_mutex_t	fork;
	struct s_philo	*right_philo;
	struct s_philo	*left_philo;
	struct s_table	*table;
}	t_philo;

/*
 * Philo table class : Public
*/

typedef struct s_table
{
	pthread_mutex_t	printer;
	pthread_mutex_t	checker;
	t_philo			*philos;
	int				number_philos;
	int				t_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_eat;
	atomic_int		all_eat;
	atomic_int		died;
	atomic_size_t	time_init;
}	t_table;

/*
 * Tools :
*/

size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_atoi(const char *str);

/*
 * Core functions :
*/

int				parser(int argc, char **argv, t_table *table);
int				args_checker(int argc, char **argv);
int				number_validator(int argc, char **argv);
int				int_validator(char *argv);
void			ft_initialize_tab(t_table *table);
atomic_size_t	get_time(void);
void			*philo_lc(void *ptr);
void			philo_go_eat(t_philo *philo);
void			actions_printer(t_philo *philo, int action);
char			*retrieve_message(int action);
void			my_sleep(t_table *table, size_t time_sleep);
void			supervisor(t_table *table);
void			end_simulation(t_table *table, pthread_t *thread_id);

#endif
