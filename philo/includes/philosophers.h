/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:30:28 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/12 16:01:00 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define HAS_TAKEN_A_FORK 1
# define IS_EATING 2
# define IS_SLEEPING 3
# define IS_THINKING 4
# define DIED 5

int	main(int argc, char **argv);

#endif
