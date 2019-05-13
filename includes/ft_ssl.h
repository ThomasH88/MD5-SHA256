/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:29:26 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/13 11:25:34 by tholzheu         ###   ########.fr       */
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
# define WORD_A 0x67452301
# define WORD_B 0xefcdab89
# define WORD_C 0x98badcfe
# define WORD_D 0x10325476

void				print_bits(unsigned char c);
void				print_bits_str(unsigned char *s);
void				print_nbits_str(unsigned char *s, size_t beg, size_t end);

typedef struct		s_flags
{
	int				p;
	int				p_done;
	int				q;
	int				r;
	int				arg;
	int				done;
}					t_flags;

typedef struct		s_vars_sha256
{
	unsigned int	v[8];
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
}					t_vars_sha256;

typedef struct		s_side_vars_sha256
{
	unsigned int	s0;
	unsigned int	s1;
	unsigned int	ch;
	unsigned int	maj;
	unsigned int	tmp1;
	unsigned int	tmp2;
}					t_side_vars_sha256;

typedef void		t_algorithm(char **args);

typedef struct		s_algolist
{
	char			*name;
	t_algorithm		*algorithm;
}					t_algolist;

/*
** algo_md5
*/
void				algo_md5(unsigned char *s, int var);

/*
** exit_errors
*/
int					exit_errors(int error_code, char *arg);

/*
** flags
*/
void				init_flags(t_flags *flags);
int					update_flags(t_flags *flags, char *s, int *j);

/*
** md5
*/
void				ft_md5(char **args);

/*
** process_message_md5
*/
void				process_message(unsigned char *new, size_t new_len,
									unsigned int words_0[4]);

/*
** side_funct
*/
unsigned int		rightrotate(unsigned int nb, int rot);
unsigned int		leftrotate(unsigned int nb, int rot);
char				*file_to_string(char *name);
char				*read_from_fd(int fd);
void				u_char_copy(unsigned char *src, unsigned char *dst,
								size_t len);

/*
** side_md5
*/
void				msg_len_to_64bit(size_t msg_len,
									unsigned char msg_64bit_len[64]);
void				add_64bit_len(unsigned char *c,
									unsigned char msg_64bit_len[64], int n);
unsigned int		uchar_ptr_to_uint(unsigned char *s);

/*
** algo_sha256
*/
void				algo_sha256(unsigned char *s, int var);

/*
** ft_sha256
*/
void				ft_sha256(char **args);

/*
** process_message_sha256
*/
void				process_message_sha256(unsigned char *new, size_t new_len,
											t_vars_sha256 *vars);

#endif
