/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sha256.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:27:45 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/13 10:56:45 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

void			msg_len_to_64bit_sha256(size_t msg_len,
				unsigned char msg_64bit_len[64])
{
	int	i;

	i = 0;
	while (msg_len >= 1)
	{
		msg_64bit_len[i++] = msg_len % 2;
		msg_len /= 2;
	}
	while (i < 64)
		msg_64bit_len[i++] = 0;
}

static void		add_64bit_len_sha256(unsigned char *c,
				unsigned char msg_64bit_len[64], int n)
{
	int	i;

	i = 128;
	while (i)
	{
		if (msg_64bit_len[n--] == 1)
			*c = *c | i;
		i >>= 1;
	}
}

static void		padding_bits_sha256(unsigned char *new, size_t msg_len,
									size_t new_len)
{
	size_t			i;
	int				n;
	unsigned char	msg_64bit_len[64];

	new[msg_len] = 128;
	i = msg_len + 1;
	while (i < new_len - 8)
		new[i++] = 0;
	n = 63;
	msg_len_to_64bit_sha256(msg_len * 8, msg_64bit_len);
	while (i < new_len)
	{
		add_64bit_len_sha256(&new[i++], msg_64bit_len, n);
		n -= 8;
	}
}

static void		print_message_digest_sha256(t_vars_sha256 *vars)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		ft_printf("%.8x", vars->v[i]);
		i++;
	}
}

void			algo_sha256(unsigned char *s, int var)
{
	size_t			msg_len;
	size_t			new_len;
	unsigned char	*new;
	t_vars_sha256	vars;

	msg_len = (ft_strlen((char *)s));
	new_len = 64 - msg_len % 64 + msg_len;
	new_len += (64 - msg_len % 64 <= 8) ? 64 : 0;
	if (!(new = (unsigned char *)ft_strnew(new_len)))
		exit(ft_printf("malloc error\n"));
	u_char_copy(s, new, msg_len);
	if (var == 1)
		free(s);
	padding_bits_sha256(new, msg_len, new_len);
	vars.v[0] = 0x6a09e667;
	vars.v[1] = 0xbb67ae85;
	vars.v[2] = 0x3c6ef372;
	vars.v[3] = 0xa54ff53a;
	vars.v[4] = 0x510e527f;
	vars.v[5] = 0x9b05688c;
	vars.v[6] = 0x1f83d9ab;
	vars.v[7] = 0x5be0cd19;
	process_message_sha256(new, new_len, &vars);
	print_message_digest_sha256(&vars);
	free(new);
}
