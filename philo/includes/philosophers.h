/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:30:24 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/31 14:58:41 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_status
{
	TOOK_A_FORK = 1,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_status;

typedef struct s_data
{
	int				alone;
	int				number_of_philos;
	int				dinner_is_over;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_must_eat;
	long			firststamp;
	pthread_mutex_t	*lock_print;
	pthread_mutex_t	*lock_dinner;
}	t_data;

typedef struct s_philo
{
	int				name;
	int				meals;
	long			lastsupper;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*mutex_lock_supper;
	pthread_mutex_t	*mutex_lock_meals;
	t_data			*data;
}	t_philo;



#endif
