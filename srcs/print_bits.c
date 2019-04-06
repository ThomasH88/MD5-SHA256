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

void	print_bits(unsigned char c)
{
	unsigned int	i;

	i = 256;
	while (i >>= 1)
		ft_printf((i & c) ? "1" : "0");
	ft_printf("\n");
}

void	print_bits_str(unsigned char *s)
{
	while (*s)
	{
		print_bits(*s);
		s++;
	}
	print_bits(*s);
}

void	print_nbits_str(unsigned char *s, size_t beg, size_t end)
{
	while (beg <= end)
		print_bits(s[beg++]);
}
