/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:32:42 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/19 13:38:01 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fd_to_str(const int fd)
{
	char		buf[BUFF_SIZE + 1];
	ssize_t		ret;
	char		*str;
	char		*tmp;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		ft_strdel(&str);
		str = tmp;
	}
	return (str);
}
