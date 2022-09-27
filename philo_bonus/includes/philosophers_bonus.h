/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 22:08:11 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/26 03:01:12 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdatomic.h>
# include <signal.h>
# include <pthread.h>

# define ERROR_SEM "Error : system failed to open semaphore\n"
# define FORK_FAILED "Error : system fork() failed\n"
# define EXIT_ALIVE 0
# define EXIT_DEAD 1

/*
 * Message type class :
*/

enum e_message_sem
{
	FORK_SEM,
	EAT_SEM,
	SLEEP_SEM,
	THINK_SEM,
	DIE_SEM
};

/*
 * Philo class : Private
*/

typedef struct s_philo_sem
{
	int					enumerator;
	atomic_int			eat_counter;
	atomic_size_t		last_eat;
	struct s_philo_sem	*right_philo;
	struct s_philo_sem	*left_philo;
	struct s_table_sem	*table;
	pid_t				process;
	pthread_t			death_checker;
}	t_philo_sem;

/*
 * Philo table class : public.
*/

typedef struct s_table_sem
{
	sem_t			*printer;
	sem_t			*checker;
	sem_t			*forks;
	t_philo_sem		*philos;
	int				n_philos;
	int				time_die;
	int				time_eat;
	int				time_slp;
	int				n_times_eat;
	atomic_int		all_eat;
	atomic_int		died;
	atomic_size_t	time_init;
}	t_table_sem;

int		parser_sem(int argc, char **argv, t_table_sem *table);
void	ft_initialize_sem(t_table_sem *table);
void	*philo_lc(void *ptr);
void	actions_printer_sem(t_philo_sem *philo, int action);
void	my_sleep_sem(t_table_sem *table, size_t time_slp);

#endif
