/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:25:49 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/09 15:27:15 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	init_flags(t_flags *flags)
{
	flags->p = 0;
	flags->p_done = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	flags->done = 0;
}

int		update_flags(t_flags *flags, char c)
{
	if (c == 'p')
		flags->p = 1;
	else if (c == 'q')
	{
		flags->q = 1;
		flags->r = 0;
	}
	else if (c == 'r' && flags->q == 0)
		flags->r = 1;
	else if (c == 's')
		return (1);
	return (0);
}
