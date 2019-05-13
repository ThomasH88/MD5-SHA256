/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_funct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:33:21 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/12 18:43:14 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

unsigned int			rightrotate(unsigned int nb, int rot)
{
	return ((nb >> rot) | (nb << (32 - rot)));
}

unsigned int			leftrotate(unsigned int nb, int rot)
{
	return ((nb << rot) | (nb >> (32 - rot)));
}

char			*file_to_string(char *name)
{
	int		fd;

	fd = open(name, O_RDONLY);
	return (read_from_fd(fd));
}

char			*read_from_fd(int fd)
{
	char	buff[10000 + 1];
	char	*str;
	int		n;
	int		i;

	i = 0;
	ft_bzero(buff, 10000 + 1);
	str = ft_strnew(1000000); // have to free this
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
