/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:49:42 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/12 20:10:47 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void	init_algoList(t_algoList algoList[HF_COUNT])
{
	algoList[0].name = "md5";
	algoList[0].algorithm = &ft_md5;
	algoList[1].name = "sha256";
	algoList[1].algorithm = &ft_sha256;
}

int		main(int argc, char **argv)
{
	t_algoList	algoList[HF_COUNT];
	int			i;

	i = 0;
	init_algoList(algoList);
	if (argc == 1)
		return (ft_printf("usage: ft_ss command [command opts] [command args]\n"));
	while (i < HF_COUNT)
	{
		if (ft_strequ(algoList[i].name, argv[1]))
			break ;
		i++;
	}
	if (i == HF_COUNT)
		return (exit_errors(0, argv[1]));
	algoList[i].algorithm(argv + 2);
	while (1);
	return (0);
}
