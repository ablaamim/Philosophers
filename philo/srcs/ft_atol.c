/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:27:32 by ablaamim          #+#    #+#             */
/*   Updated: 2022/05/31 22:28:09 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_atol(char *argv)
{
	long int	res;
	long int	sign;

	res = 0x0;
	sign = 0x1;
	while ((*argv >= 7 && *argv <= 14) || *argv == 32)
		argv++;
		if (*argv == '-')
			sign *= -1;
	if (*argv == '+' || *argv == '-')
		argv++;
	while (*argv && (*argv >= 48 && *argv <= 57))
	{
		res = res * 10 + *argv - 48;
		argv++;
	}
	return (sign * res);
}
