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

void	msg_len_to_64bit(size_t msg_len, unsigned char msg_64bit_len[64])
{
	int	i;

	i = 63;
	while (msg_len >= 1)
	{
		msg_64bit_len[i--] = msg_len % 2;
		msg_len /= 2;
	}
	while (i >= 0)
		msg_64bit_len[i--] = 0;
}

void	add_64bit_len(unsigned char *c, unsigned char msg_64bit_len[64], int n)
{
	int	i;

	i = 256;
	while (i >>= 1)
		if (msg_64bit_len[n++] == 1)
			*c = *c | i;
}
