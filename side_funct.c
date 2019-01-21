/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:49:42 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/19 09:17:21 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			u_char_copy(unsigned char *src, unsigned char *dst, size_t len)
{
	size_t		i;

	if (!src || !dst)
		return ;
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

unsigned long long	ft_pow(int nb, int pow)
{
	unsigned long long	ans;

	if (pow == 0)
		return (1);
	ans = nb;
	while (--pow)
		ans *= nb;
	return (ans);
}
