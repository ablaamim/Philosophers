/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:58:50 by ablaamim          #+#    #+#             */
/*   Updated: 2022/07/13 16:26:00 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/*
 * Verify if input character is a digit.
 * -> Return true if character is found.
 * -> Else return false.
*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0x1);
	else
		return (0x0);
}

/*
 * Convert ascii strings into integers.
*/

int	ft_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0x0;
	sign = 0x1;
	if ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = (res * 10) + *str - 48;
		str++;
	}
	return (res * sign);
}
/*
int	main()
{
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("-42"));
	printf("%d\n", ft_atoi("--1337"));
	printf("%d\n", ft_atoi("++420"));
	printf("%d\n", ft_atoi("1337"));
	return (0x0);
}
*/
