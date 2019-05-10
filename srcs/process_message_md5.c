/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_message_md5.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:57:21 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/09 20:40:56 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static unsigned int	aux_processing(int *i, unsigned int words[4], unsigned int *g)
{
	unsigned char	*f;
	unsigned char	*u_words[3];

	u_words[0] = 
	u_words[0] = 
	u_words[0] = 
	if (*i >= 0 && *i <= 15)
	{
		*g = *i; // finished here
		f = auxiliary_functions("F", word[1], word[2], word[3]);
	}
	else if (*i >= 16 && *i <= 31)
	{
		*g = (5 * (*i) + 1) % 16;
	}
	else if (*i >= 32 && *i <= 47)
	{
		*g = (3 * (*i) + 5) % 16;
	}
	else if (*i >= 48 && *i <= 63)
	{
		*g = (7 * (*i)) % 16;
	}
	(*i)++;
}

void				process_message(unsigned char *new, size_t new_len)
{
	int					i[2];
	unsigned int		words_0[4];
	unsigned char		*words[4];
	unsigned int		f;
	unsigned int		g;

	i[0] = 0;
	words_0[0] = WORD_A;
	words_0[1] = WORD_B;
	words_0[2] = WORD_C;
	words_0[3] = WORD_D;
	while (i[0] < (new_len / 512))
	{
		words[0] = WORD_A;
		words[1] = WORD_B;
		words[2] = WORD_C;
		words[3] = WORD_D;
		i[1] = 0;
		while (i[1] < 64)
			f = aux_processing(&i[1], &g, words);
	}
}
