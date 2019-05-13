/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:34:40 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/12 20:14:29 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned char	*bitwise_and(unsigned char *a, unsigned char *b)
{
	int				i;
	unsigned char	*c;

	c = (unsigned char *)malloc(sizeof(unsigned char) * 4); // might need to free a and b
	i = 0;
	while(i < 4)
	{
		c[i] = a[i] & b[i];
		i++;
	}
	i = 0;
	return (c);
}

unsigned char	*bitwise_or(unsigned char *a, unsigned char *b)
{
	int				i;
	unsigned char	*c;

	c = (unsigned char *)malloc(sizeof(unsigned char) * 4); // might need to free a and b
	i = 0;
	while(i < 4)
	{
		c[i] = a[i] | b[i];
		i++;
	}
	return (c);
}

unsigned char	*bitwise_xor(unsigned char *a, unsigned char *b)
{
	int				i;
	unsigned char	*c;

	c = (unsigned char *)malloc(sizeof(unsigned char) * 4); // might need to free a and b
	i = 0;
	while(i < 4)
	{
		c[i] = a[i] ^ b[i];
		i++;
	}
	return (c);
}

unsigned char	*bitwise_complement(unsigned char *a)
{
	int				i;
	unsigned char	*c;

	c = (unsigned char *)malloc(sizeof(unsigned char) * 4); // might need to free a and b
	i = 0;
	while(i < 4)
	{
		c[i] = ~a[i];
		i++;
	}
	return (c);
}