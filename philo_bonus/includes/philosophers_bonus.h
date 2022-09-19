/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:03:10 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/17 22:11:40 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <ctype.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define TOOK_FORK 1
# define IS_EATING 2
# define IS_SLEEPING 3
# define IS_THINKING 4
# define HAS_DIED 5

typedef struct s_sem_data
{
	int		philo_is_alone;
	int		number_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_times_each_philosopher_must_eat;
	long	first_stamp;
	sem_t	*lock_print;
}	t_sem_data;

typedef struct s_sem_philo
{
	pid_t		process;
	t_sem_data	*data;
	int			enumerator;
	int			meals;
	long		last_supper;
	sem_t		*fork_left;
	sem_t		*fork_right;
	sem_t		*forks;
	void		*philos;
}	t_sem_philo	;

void	ft_parse_and_initialize_sem(int argc, char **argv, t_sem_data *data);
void	initializer_of_data_sem(t_sem_data *data, sem_t **forks, t_sem_philo **philos);
void	sema_forks_initializer(int n_philos, t_sem_data *data, sem_t **forks, t_sem_philo **philos);
void	sema_philos_initializer(int n_philos, t_sem_data *data, sem_t **forks, t_sem_philo **philos);
void	philosophers_sem_simulator(int n_philos, t_sem_philo *philos);
int		process_constructor(pid_t *process, int (*f)(void *), t_sem_philo *philos);
int		ft_routine_sem(void *ptr);
void	sleeper(int time_ms, t_sem_philo *philo);
void	actions_sem_printer(t_sem_philo *philo, int action);
int		joining_process(t_sem_philo *philos);
void	simulation_failed_sem(t_sem_data *data, sem_t *forks, t_sem_philo *philos);
void	philosophers_exit(t_sem_data *data, sem_t *forks, t_sem_philo *philos, int exit_code);
void	philo_sema_go_eat(t_sem_philo *philo);
void	philo_go_sleep(t_sem_philo *philo);
void	philo_go_think(t_sem_philo *philo);

#endif
