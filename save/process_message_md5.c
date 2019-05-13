/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_message_md5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:57:21 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/13 10:12:48 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

/*
** Number of rotations table
*/
int rot_table[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21,
	6, 10, 15, 21, 6, 10, 15, 21};

/*
** table constructed from the sine wave
*/
int sine_table[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static unsigned char	*aux_processing(int i, unsigned int words[4], unsigned int *g)
{
	unsigned char	*u_words[3];

	u_words[0] = uint_to_uchar_ptr(words[1]);
	u_words[1] = uint_to_uchar_ptr(words[2]);
	u_words[2] = uint_to_uchar_ptr(words[3]);
	if (i >= 0 && i <= 15)
	{
		*g = i;
		return (auxiliary_functions("F", u_words[0], u_words[1], u_words[2]));
	}
	else if (i >= 16 && i <= 31)
	{
		*g = (5 * (i) + 1) % 16;
		return (auxiliary_functions("G", u_words[0], u_words[1], u_words[2]));
	}
	else if (i >= 32 && i <= 47)
	{
		*g = (3 * i + 5) % 16;
		return (auxiliary_functions("H", u_words[0], u_words[1], u_words[2]));
	}
	*g = (7 * i) % 16;
	return (auxiliary_functions("I", u_words[0], u_words[1], u_words[2]));
}

static void				chunk_to_words(unsigned int m[16], unsigned char *new, int i)
{
	int				j;
	int				k;
	int				l;
	unsigned int	tmp;

	j = 0;
	k = 0;
	while (j < 16)
	{
		tmp = uchar_ptr_to_uint(&new[i * 64 + k]);
		l = 4;
		m[j] = 0;
		while (l--)
		{
			m[j] <<= 8;
			m[j] += tmp & 0xff;
			tmp >>= 8;
		}
		j++;
		k += 4;
	}
}

/*void					print_chunk(unsigned int m[16])*/
/*{*/
	/*int		i;*/

	/*i = 0;*/
	/*while (i < 16)*/
	/*{*/
		/*printf("[%2d] %u\n", i, m[i]);*/
		/*i++;*/
	/*}*/
/*}*/

static void				update_words(unsigned int words_0[4], unsigned int words[4], int update)
{
	if (update == 1)
	{
		words[0] = words_0[0];
		words[1] = words_0[1];
		words[2] = words_0[2];
		words[3] = words_0[3];
	}
	else
	{
		words_0[0] = words_0[0] + words[0];
		words_0[1] = words_0[1] + words[1];
		words_0[2] = words_0[2] + words[2];
		words_0[3] = words_0[3] + words[3];
	}
}

void					process_message(unsigned char *new, size_t new_len, unsigned int words_0[4])
{
	int					i[2];
	unsigned int		words[4];
	unsigned int		f;
	unsigned int		g;
	unsigned int		m[16];

	i[0] = 0;
	g = 0;
	while ((size_t)i[0] < (new_len / 64))
	{
		chunk_to_words(m, new, i[0]);
		update_words(words_0, words, 1);
		i[1] = -1;
		while (++i[1] < 64)
		{
			f = uchar_ptr_to_uint(aux_processing(i[1], words, &g));
			f = f + words[0] + sine_table[i[1]] + m[g];
			words[0] = words[3];
			words[3] = words[2];
			words[2] = words[1];
			words[1] = words[1] + leftrotate(f, rot_table[i[1]]);
		}
		update_words(words_0, words, 2);
		i[0]++;
	}
}
