/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_md5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:59:50 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/13 11:03:43 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void				padding_bits(unsigned char *new,
							size_t msg_len, size_t new_len)
{
	size_t			i;
	int				n;
	unsigned char	msg_64bit_len[64];

	new[msg_len] = 128;
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

static void				print_message_digest(unsigned int msg[4])
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_printf("%.2x%.2x%.2x%.2x", msg[i] & 0xff, (msg[i] >> 8) & 0xff,
				(msg[i] >> 16) & 0xff, (msg[i] >> 24) & 0xff);
		i++;
	}
}

void					algo_md5(unsigned char *s, int var)
{
	size_t			msg_len;
	size_t			new_len;
	unsigned char	*new;
	unsigned int	words_0[4];

	msg_len = (ft_strlen((char *)s));
	new_len = 64 - msg_len % 64 + msg_len;
	new_len += (64 - msg_len % 64 <= 8) ? 64 : 0;
	if (!(new = (unsigned char *)ft_strnew(new_len)))
		exit(ft_printf("malloc error\n"));
	u_char_copy(s, new, msg_len);
	if (var == 1)
		free(s);
	padding_bits(new, msg_len, new_len);
	words_0[0] = WORD_A;
	words_0[1] = WORD_B;
	words_0[2] = WORD_C;
	words_0[3] = WORD_D;
	process_message(new, new_len, words_0);
	print_message_digest(words_0);
	free(new);
}
