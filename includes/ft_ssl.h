/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:29:26 by tholzheu          #+#    #+#             */
/*   Updated: 2019/04/06 16:52:49 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# define HF_COUNT 2

void			print_bits(unsigned char c);
void			print_bits_str(unsigned char *s);
void			print_nbits_str(unsigned char *s, size_t beg, size_t end);

typedef			void t_algorithm(unsigned char *s);

typedef struct 		s_algoList
{
	char		*name;
	t_algorithm	*algorithm;
}			t_algoList;

/*
** flags
*/
//int			isvalid_flag(char *s);


/*
** md5
*/
void			algo_md5(unsigned char *s);

/*
** side_md5
*/
void			msg_len_to_64bit(size_t msg_len, unsigned char msg_64bit_len[64]);
void			add_64bit_len(unsigned char *c, unsigned char msg_64bit_len[64], int n);

/*
** side_funct
*/
void			u_char_copy(unsigned char *src, unsigned char *dst, size_t len);
unsigned long long	ft_pow(int nb, int pow);

#endif
