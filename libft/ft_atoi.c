/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:05:29 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/03 13:21:30 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	ans;
	int		sign;

	sign = 1;
	ans = 0;
	if (str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\r'
					|| *str == '\v' || *str == '\f' || *str == '\t'))
			str++;
		if (*str == '-' && str++)
			sign = -1;
		else if (*str == '+' && str++)
			sign = 1;
		while (*str && *str >= '0' && *str <= '9')
			ans = ans * 10 + (*str++ - '0');
	}
	if (ans * sign > 2147483647 || ans * sign < -2147483648)
		return (0);
	return (sign * ans);
}
