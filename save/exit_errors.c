/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:02:56 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/12 11:25:38 by tholzheu         ###   ########.fr       */
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
	else if (error_code == 1)
		exit(ft_printf("md5: option requires an argument -- s\nusage: md5 [-pqr] [-s string] [files ...]\n"));
	else if (error_code == 2)
		ft_printf("md5: %s: No such file or directory\n", arg);
	else if (error_code == 3)
		exit(ft_printf("md5: illegal option -- %c\nusage: md5 [-pqr] [-s string] [files ...]\n", arg[0]));
	else if (error_code == 4)
		ft_printf("sha256: %s: No such file or directory\n", arg);
	else if (error_code == 5)
		exit(ft_printf("sha256: option requires an argument -- s\nusage: md5 [-pqr] [-s string] [files ...]\n"));
	return (-1);
}
