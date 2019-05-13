/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:49:42 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/13 11:15:42 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void		init_algolist(t_algolist algolist[HF_COUNT])
{
	algolist[0].name = "md5";
	algolist[0].algorithm = &ft_md5;
	algolist[1].name = "sha256";
	algolist[1].algorithm = &ft_sha256;
}

int				main(int argc, char **argv)
{
	t_algolist	algolist[HF_COUNT];
	int			i;

	i = 0;
	init_algolist(algolist);
	if (argc == 1)
	{
		ft_printf("usage: ft_ss command [command opts] [command args]\n");
		return (1);
	}
	while (i < HF_COUNT)
	{
		if (ft_strequ(algolist[i].name, argv[1]))
			break ;
		i++;
	}
	if (i == HF_COUNT)
		return (exit_errors(0, argv[1]));
	algolist[i].algorithm(argv + 2);
	return (0);
}
