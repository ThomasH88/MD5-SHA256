/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:29:26 by tholzheu          #+#    #+#             */
/*   Updated: 2019/04/08 21:11:18 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# define HF_COUNT 2
# define WORD_A 0x01234567
# define WORD_B 0x89abcdef
# define WORD_C 0xfedcba98
# define WORD_D 0x76543210

void				print_bits(unsigned char c);
void				print_bits_str(unsigned char *s);
void				print_nbits_str(unsigned char *s, size_t beg, size_t end);

typedef struct 		s_flags
{
	int				p;
	int				p_done;
	int				q;
	int				r;
	int				s;
	int				done;
}					t_flags;

typedef				void t_algorithm(char **args);
typedef struct 		s_algoList
{
	char			*name;
	t_algorithm		*algorithm;
}					t_algoList;

/*
** flags
*/
void				init_flags(t_flags *flags);
int					update_flags(t_flags *flags, char c);

/*
** exit_errors
*/
int					exit_errors(int error_code, char *arg);

/*
** md5
*/
void				algo_md5(unsigned char *s);
void				ft_md5(char **args);

/*
** side_md5
*/
void				msg_len_to_64bit(size_t msg_len, unsigned char msg_64bit_len[64]);
void				add_64bit_len(unsigned char *c, unsigned char msg_64bit_len[64], int n);

/*
** side_funct
*/
char				*read_from_fd(int fd);
void				u_char_copy(unsigned char *src, unsigned char *dst, size_t len);
unsigned long long	ft_pow(int nb, int pow);

#endif
