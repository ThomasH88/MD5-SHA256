/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:02:56 by tholzheu          #+#    #+#             */
/*   Updated: 2019/04/08 15:59:12 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

int		exit_errors(int error_code, char *arg)
{
	if (error_code == 0)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n");
		ft_printf("Standard commands:\n\nMessage Digest commands:\nmd5\nsha256\n\n");
		ft_printf("Cipher commands:\n", arg);
	}
	if (error_code == 1)
		exit(ft_printf("md5: option requires an argument -- s\nusage: md5 [-pqr] [-s string] [files ...]\n"));
	return (-1);
}
