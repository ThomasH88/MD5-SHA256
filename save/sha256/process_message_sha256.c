/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_message_sha256.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 12:19:53 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/12 20:05:52 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

/*
** (first 32 bits of the fractional parts of the
**	cube roots of the first 64 primes 2..311):
*/

unsigned long int g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

static void				chunk_to_words_sha256(unsigned int w[64],
												unsigned char *new, int i)
{
	int				j;
	int				k;

	j = 0;
	k = 0;
	while (j < 16)
	{
		w[j] = uchar_ptr_to_uint(&new[i * 64 + k]);
		j++;
		k += 4;
	}
}

static void				update_vars_and_hashes(t_vars_sha256 *vars, int code)
{
	if (code == 1)
	{
		vars->a = vars->v[0];
		vars->b = vars->v[1];
		vars->c = vars->v[2];
		vars->d = vars->v[3];
		vars->e = vars->v[4];
		vars->f = vars->v[5];
		vars->g = vars->v[6];
		vars->h = vars->v[7];
	}
	else
	{
		vars->v[0] += vars->a;
		vars->v[1] += vars->b;
		vars->v[2] += vars->c;
		vars->v[3] += vars->d;
		vars->v[4] += vars->e;
		vars->v[5] += vars->f;
		vars->v[6] += vars->g;
		vars->v[7] += vars->h;
	}
}

static unsigned int		aux_functions_sha256(unsigned int w[64],
						t_vars_sha256 *vars, int i, int code)
{
	int		a;

	if (code == 1)
		return (rightrotate(w[i - 15], 7) ^
				rightrotate(w[i - 15], 18) ^ (w[i - 15] >> 3));
	else if (code == 2)
		return (rightrotate(w[i - 2], 17) ^
				rightrotate(w[i - 2], 19) ^ (w[i - 2] >> 10));
	else if (code == 3)
		return (rightrotate(vars->e, 6) ^
				rightrotate(vars->e, 11) ^ rightrotate(vars->e, 25));
	else if (code == 4)
		return ((vars->e & vars->f) ^ (~vars->e & vars->g));
	else if (code == 5)
		return (rightrotate(vars->a, 2) ^
				rightrotate(vars->a, 13) ^ rightrotate(vars->a, 22));
	else
		a = 1;
	return ((vars->a & vars->b) ^ (vars->a & vars->c) ^ (vars->b & vars->c));
}

static void				compression_fn(unsigned int w[64], t_vars_sha256 *vars)
{
	int					i;
	t_side_vars_sha256	s_vars;

	i = 0;
	while (i < 64)
	{
		s_vars.s1 = aux_functions_sha256(w, vars, i, 3);
		s_vars.ch = aux_functions_sha256(w, vars, i, 4);
		s_vars.tmp1 = vars->h + s_vars.s1 + s_vars.ch + g_k[i] + w[i];
		s_vars.s0 = aux_functions_sha256(w, vars, i, 5);
		s_vars.maj = aux_functions_sha256(w, vars, i, 6);
		s_vars.tmp2 = s_vars.s0 + s_vars.maj;
		vars->h = vars->g;
		vars->g = vars->f;
		vars->f = vars->e;
		vars->e = vars->d + s_vars.tmp1;
		vars->d = vars->c;
		vars->c = vars->b;
		vars->b = vars->a;
		vars->a = s_vars.tmp1 + s_vars.tmp2;
		i++;
	}
}

void					process_message_sha256(unsigned char *new,
						size_t new_len, t_vars_sha256 *vars)
{
	unsigned int	w[64];
	int				i;
	int				j;
	unsigned int	s0;
	unsigned int	s1;

	i = 0;
	while ((size_t)i < (new_len / 64))
	{
		chunk_to_words_sha256(w, new, i);
		j = 16;
		while (j < 64)
		{
			s0 = aux_functions_sha256(w, vars, j, 1);
			s1 = aux_functions_sha256(w, vars, j, 2);
			w[j] = w[j - 16] + s0 + w[j - 7] + s1;
			j++;
		}
		update_vars_and_hashes(vars, 1);
		compression_fn(w, vars);
		update_vars_and_hashes(vars, 2);
		i++;
	}
}
