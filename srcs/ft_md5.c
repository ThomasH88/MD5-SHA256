/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:48:11 by tholzheu          #+#    #+#             */
/*   Updated: 2019/04/08 18:13:46 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void		output_formatting_md5(t_flags *flags, char *msg, int is_file)
{
	int		a = 1;
	if (a)
		algo_md5((unsigned char *)msg);
	else
	{
		if (flags->p == 1 && flags->p_done == 0)
		{
			flags->p_done = 1;
			flags->p = 0;
			ft_printf("%smsg digest\n", msg);
		}
		else
		{
			if (is_file == 0 && msg == NULL)
				exit_errors(1, NULL);
			if (is_file)
				ft_printf("function that gets the file name '%s' and returns the file as a string\n", msg);
			if (flags->q)
				ft_printf("MD5 msg digest of '%s'\n", msg);
			else if (flags->r)
				ft_printf("MD5 msg digest \"%s\"\n", msg);
			else
				ft_printf("MD5 (\"%s\") = msg digest\n", msg);
		}
	}
}

void			ft_md5(char **args)
{
	int			i;
	int			j;
	t_flags		flags;

	i = 0;
	init_flags(&flags);
	while (args && args[i])
	{
		j = 0;
		if (flags.done == 0 && args[i][j] && args[i][j] == '-')
			while(args[i][++j])
			{
				if (update_flags(&flags, args[i][j]) == 1)
				{
					if (args[i][j + 1])
						output_formatting_md5(&flags, args[i] + j + 1, 0);
					else
						output_formatting_md5(&flags, args[++i], 0);
				}
				if (flags.p == 1 && flags.p_done == 0)
					output_formatting_md5(&flags, read_from_fd(0), 0);
				else if (flags.p == 1 && flags.p--)
					ft_printf("d41d8cd98f00b204e9800998ecf8427e\n");
			}
		else if ((flags.done = 1))
			output_formatting_md5(&flags, args[i], 1);
		i++;
	}
}
