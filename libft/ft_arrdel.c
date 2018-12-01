/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:12:44 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 18:24:58 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrdel(char ***arr)
{
	int		i;
	char	**del;

	if (!arr)
		return ;
	del = *arr;
	i = 0;
	while (del && del[i])
		ft_strdel(&del[i++]);
	free(*arr);
	*arr = NULL;
}
