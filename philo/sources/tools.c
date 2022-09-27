/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:13:20 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/25 20:56:47 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	if (str == 0x0)
		return (0x0);
	res = 0x0;
	sign = 0x1;
	while (*str == 32 || (*str >= 7 && *str <= 14))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0x0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (i < n)
		return ((unsigned char )str1[i] - (unsigned char)str2[i]);
	else
		return (0x0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0x0;
	while (str[len])
		len++;
	return (len);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
