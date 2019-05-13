/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:25:49 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/11 16:35:15 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	init_flags(t_flags *flags)
{
	flags->p = 0;
	flags->p_done = 0;
	flags->q = 0;
	flags->r = 0;
	flags->arg = 0;
	flags->done = 0;
}

int		update_flags(t_flags *flags, char *s, int *j)
{
	while (s[*j])
	{
		if (s[*j] == 'p')
		{
			flags->p = 1;
			flags->arg = 1;
		}
		else if (s[*j] == 'q')
		{
			flags->q = 1;
			flags->r = 0;
		}
		else if (s[*j] == 'r' && flags->q == 0)
			flags->r = 1;
		else if (s[*j] == 's' && (flags->arg = 1))
			return (1);
		else if (s[*j] != 'r')
			exit_errors(3, &s[*j]);
		(*j)++;
	}
	return (0);
}
