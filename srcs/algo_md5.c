/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:59:50 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/09 20:41:24 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static unsigned char	*auxiliary_functions(char *name, unsigned char *x, unsigned char *y, unsigned char *z)
{
	if (name[0] == 'F')
		return (bitwise_or(bitwise_and(x, y), bitwise_and(bitwise_complement(x), z)));
	else if (name[0] == 'G')
		return (bitwise_or(bitwise_and(x, z), bitwise_and(y, bitwise_complement(z))));
	else if (name[0] == 'H')
		return (bitwise_xor(x, bitwise_xor(y, z)));
	return (bitwise_xor(y, bitwise_or(x, bitwise_complement(z))));
}

static void				padding_bits(unsigned char *new, size_t msg_len, size_t new_len)
{
	size_t			i;
	int				n;
	unsigned char	msg_64bit_len[64];

	ft_printf("msg_len = %llu  new_len = %llu\n", msg_len, new_len);
	new[msg_len] = 128; //append a single 1 bit followed by 0's
	i = msg_len + 1;
	while (i < new_len - 8)
		new[i++] = 0;
	n = 63;
	msg_len_to_64bit(msg_len * 8, msg_64bit_len);
	while (i < new_len - 4)
	{
		add_64bit_len(&new[i++], msg_64bit_len, n);
		n -= 8;
	}
	n = 32;
	while (i < new_len)
	{
		add_64bit_len(&new[i++], msg_64bit_len, n);
		n -= 8;
	}
}

void					algo_md5(unsigned char *s)
{
	size_t			msg_len;
	size_t			new_len;
	unsigned char	*new;

	msg_len = (ft_strlen((char *)s) + 1);//+1 because of the \0
	new_len = 64 - msg_len % 64 + msg_len;
	new_len += (64 - msg_len % 64 <= 8) ? 64 : 0;
	if (!(new = (unsigned char *)ft_strnew(new_len)))
		exit(ft_printf("malloc error\n"));
	u_char_copy(s, new, msg_len);
	padding_bits(new, msg_len, new_len);
	print_nbits_str(new, 0, 127);
	process_message(new, new_len);
}
