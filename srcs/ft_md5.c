/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:48:11 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/13 11:08:13 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void		format_options_md5(t_flags *flags, char *msg, int fmt_nb)
{
	if (fmt_nb == 1)
	{
		flags->p_done = 1;
		flags->p = 0;
		ft_printf("%s", msg);
		algo_md5((unsigned char *)msg, 0);
		ft_printf("\n");
	}
	else if (fmt_nb == 2)
	{
		if (access(msg, R_OK) == -1)
		{
			exit_errors(2, msg);
			return ;
		}
		if (!flags->q && !flags->r)
			ft_printf("MD5 (%s) = ", msg);
		algo_md5((unsigned char *)file_to_string(msg), 1);
		if (flags->r)
			ft_printf(" %s", msg);
		ft_printf("\n");
	}
}

static void		output_formatting_md5(t_flags *flags, char *msg, int is_file)
{
	if (flags->p == 1 && flags->p_done == 0)
		format_options_md5(flags, msg, 1);
	else
	{
		if (is_file == 0 && msg == NULL)
			exit_errors(1, NULL);
		if (is_file && (flags->arg = 1))
			format_options_md5(flags, msg, 2);
		else if (flags->q)
		{
			algo_md5((unsigned char *)msg, 0);
			ft_printf("\n");
		}
		else if (flags->r)
		{
			algo_md5((unsigned char *)msg, 0);
			ft_printf(" \"%s\"\n", msg);
		}
		else if (!is_file)
		{
			ft_printf("MD5 (\"%s\") = ", msg);
			algo_md5((unsigned char *)msg, 0);
			ft_printf("\n");
		}
	}
}

static void		ft_md5_helper(char **args, t_flags *flags, int *i, int j)
{
	if (args[*i][++j])
	{
		if (update_flags(flags, args[*i], &j) == 1)
		{
			if (args[*i][j + 1])
				output_formatting_md5(flags, args[*i] + j + 1, 0);
			else
				output_formatting_md5(flags, args[++(*i)], 0);
		}
		if (flags->p == 1 && flags->p_done == 0)
			output_formatting_md5(flags, read_from_fd(0), 0);
		else if (flags->p == 1 && flags->p--)
			ft_printf("d41d8cd98f00b204e9800998ecf8427e\n");
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
			ft_md5_helper(args, &flags, &i, j);
		else if ((flags.done = 1))
			output_formatting_md5(&flags, args[i], 1);
		i++;
	}
	if (flags.arg == 0 && (flags.q = 1))
		output_formatting_md5(&flags, read_from_fd(0), 0);
}
