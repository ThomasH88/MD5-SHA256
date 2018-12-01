/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:36:34 by tholzheu          #+#    #+#             */
/*   Updated: 2018/11/15 19:46:38 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_arrdel_size(char ***arr, size_t size)
{
	char	**del;

	if (!arr)
		return ;
	del = *arr;
	if (*arr)
	{
		while (size--)
		{
			ft_strdel(del);
			del++;
		}
	}
	free(*arr);
	*arr = NULL;
}
