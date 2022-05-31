/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:33:59 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/31 14:56:53 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data			*data;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	ft_init_arguments(argc, argv, &data);
	return (EXIT_SUCCESS);
}
