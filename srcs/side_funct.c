/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:49:42 by tholzheu          #+#    #+#             */
/*   Updated: 2019/04/08 15:58:10 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

char			*read_from_fd(int fd)
{
	char	buff[10000 + 1];
	char	*str;
	int		n;
	int		i;

	i = 0;
	ft_bzero(buff, 10000 + 1);
	str = ft_strnew(1000000);
	while((n = read(fd, buff, 10000)) > 0)
	{
		ft_strcpy(&str[i], buff);
		ft_bzero(buff, 10000 + 1);
		i += n;
	}
	return (str);
}

void			u_char_copy(unsigned char *src, unsigned char *dst, size_t len)
{
	size_t		i;

	if (!src || !dst)
		return ;
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

unsigned long long	ft_pow(int nb, int pow)
{
	unsigned long long	ans;

	if (pow == 0)
		return (1);
	ans = nb;
	while (--pow)
		ans *= nb;
	return (ans);
}
