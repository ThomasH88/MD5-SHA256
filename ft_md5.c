/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:01:43 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/20 15:20:35 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		ft_md5(char **args)
{
	unsigned char	flags;
	int				i;
	int				count;

	i = 0;
	count = 0;
	flags = 0;
	if (args[i] == NULL)
		algo_md5(fd_to_str(0), 0);//char * has to be freed in algo_md5
	while (args[i])
	{
		if (args[i][0] == '-')
		{
			if (flag_parsing(args[i], &flags) == 
		}
		/*
		** if wrong file all the next arguments are treated as files
		*/
	}
}
