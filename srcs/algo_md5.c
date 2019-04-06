/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:49:42 by tholzheu          #+#    #+#             */
/*   Updated: 2019/04/06 16:50:37 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void	padding_bits(unsigned char *new, size_t msg_len, size_t new_len)
{
	size_t		i;
	int		n;
	unsigned char	msg_64bit_len[64];

	ft_printf("msg_len = %llu  new_len = %llu\n", msg_len, new_len);
	new[msg_len] = 128; //append a single 1 bit followed by 0's
	i = msg_len + 1;
	while (i < new_len - 8)
		new[i++] = 0;
	n = 32;
	msg_len_to_64bit(msg_len * 8, msg_64bit_len);
	while (i < new_len - 4)
	{
		add_64bit_len(&new[i++], msg_64bit_len, n);
		n += 8;
	}
	n = 0;
	while (i < new_len)
	{
		add_64bit_len(&new[i++], msg_64bit_len, n);
		n += 8;
	}
	print_nbits_str(new, 0, 63);
}

void		algo_md5(unsigned char *s)
{
	size_t		msg_len;
	size_t		new_len;
	unsigned char	*new;

	msg_len = (ft_strlen((char *)s) + 1);//+1 because of the \0
	new_len = 64 - msg_len % 64 + msg_len;
	new_len += (64 - msg_len % 64 <= 8) ? 64 : 0;
	if (!(new = (unsigned char *)malloc(sizeof(unsigned char) * new_len)))
		return ;
	u_char_copy(s, new, msg_len);
	padding_bits(new, msg_len, new_len);
}
