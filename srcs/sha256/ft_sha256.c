/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 11:13:16 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/13 10:57:52 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ssl.h"

static void		format_options_sha256(t_flags *flags, char *msg, int fmt_nb)
{
	if (fmt_nb == 1)
	{
		flags->p_done = 1;
		flags->p = 0;
		ft_printf("%s", msg);
		algo_sha256((unsigned char *)msg, 0);
		ft_printf("\n");
	}
	else if (fmt_nb == 2)
	{
		if (access(msg, R_OK) == -1)
		{
			exit_errors(4, msg);
			return ;
		}
		if (!flags->q && !flags->r)
			ft_printf("SHA256 (%s) = ", msg);
		algo_sha256((unsigned char *)file_to_string(msg), 1);
		if (flags->r)
			ft_printf(" %s", msg);
		ft_printf("\n");
	}
}

static void		output_formatting_sha256(t_flags *flags, char *msg, int is_file)
{
	if (flags->p == 1 && flags->p_done == 0)
		format_options_sha256(flags, msg, 1);
	else
	{
		if (is_file == 0 && msg == NULL)
			exit_errors(5, NULL);
		if (is_file && (flags->arg = 1))
			format_options_sha256(flags, msg, 2);
		else if (flags->q)
		{
			algo_sha256((unsigned char *)msg, 0);
			ft_printf("\n");
		}
		else if (flags->r)
		{
			algo_sha256((unsigned char *)msg, 0);
			ft_printf(" \"%s\"\n", msg);
		}
		else if (!is_file)
		{
			ft_printf("SHA256 (\"%s\") = ", msg);
			algo_sha256((unsigned char *)msg, 0);
			ft_printf("\n");
		}
	}
}

static void		ft_sha256_helper(char **args, t_flags *flags, int *i, int j)
{
	if (args[*i][++j])
	{
		if (update_flags(flags, args[*i], &j) == 1)
		{
			if (args[*i][j + 1])
				output_formatting_sha256(flags, args[*i] + j + 1, 0);
			else
				output_formatting_sha256(flags, args[++(*i)], 0);
		}
		if (flags->p == 1 && flags->p_done == 0)
			output_formatting_sha256(flags, read_from_fd(0), 0);
		else if (flags->p == 1 && flags->p--)
		{
			ft_printf("e3b0c44298fc1c149afbf4c8996fb9");
			ft_printf("2427ae41e4649b934ca495991b7852b855\n");
		}
	}
}

void			ft_sha256(char **args)
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
			ft_sha256_helper(args, &flags, &i, j);
		else if ((flags.done = 1))
			output_formatting_sha256(&flags, args[i], 1);
		i++;
	}
	if (flags.arg == 0 && (flags.q = 1))
		output_formatting_sha256(&flags, read_from_fd(0), 0);
}
