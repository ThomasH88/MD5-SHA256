/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:19:04 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/20 15:18:26 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int			flag_parsing(char *s, unsigned char *flags)
{
	while (s && *s)
	{
		if (!isvalid_flag(*s))
			return (-1);//stop reading args
		else if (*s == 's' && *(s + 1))
		{
			algo_md5(s + 1, *flags);
			return (0);//do nothing and go to next arg
		}
		else if (*s == 's')
			return (1);//treat next arg as string
		else if (*s == 'p')
			algo_md5(fd_to_str(0), 0);
		else if (*s == 'q')
			*flags = FLAG_Q;
		else if (*s == 'r' && *flags == 0)
			*flags = FLAG_R;
	}
}

int			isvalid_flag(char c)
{
	if (*c == 'p' || *c == 'q' || *c == 'r' || *c == 's')
		return (1);
	return (0);
}
