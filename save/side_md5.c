/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:50:46 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/12 11:54:56 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void			msg_len_to_64bit(size_t msg_len, unsigned char msg_64bit_len[64])
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

void			add_64bit_len(unsigned char *c, unsigned char msg_64bit_len[64], int n)
{
	int	i;

	i = 1;
	while (i <= 128)
	{
		if (msg_64bit_len[n--] == 1)
			*c = *c | i;
		i <<= 1;
	}
}

unsigned int	uchar_ptr_to_uint(unsigned char *s)
{
	int				i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (i < 4)
	{
		ret <<= 8;
		ret += (unsigned int)s[i++];
	}
	return (ret);
}

unsigned char	*uint_to_uchar_ptr(unsigned int nb)
{
	int				i;
	unsigned char	*s;

	s = (unsigned char *)malloc(sizeof(unsigned char) * 4); // we have to free this
	if (s == NULL)
		exit(0);
	i = 4;
	while (i--)
	{
		s[i] = nb & 0xff;
		nb >>= 8;
	}
	return (s);
}
