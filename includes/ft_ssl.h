/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:29:26 by tholzheu          #+#    #+#             */
/*   Updated: 2019/05/09 20:41:27 by tholzheu         ###   ########.fr       */
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

/*
** Number of rotations table
*/

int rot_table[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21,
	6, 10, 15, 21, 6, 10, 15, 21};

/*
** table constructed from the sine wave
*/

int sine_table[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

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
** bitwise_words
*/
unsigned char		*bitwise_and(unsigned char *a, unsigned char *b);
unsigned char		*bitwise_or(unsigned char *a, unsigned char *b);
unsigned char		*bitwise_xor(unsigned char *a, unsigned char *b);
unsigned char		*bitwise_complement(unsigned char *a);

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
unsigned int		uchar_ptr_to_uint(unsigned char *s);
unsigned char		*uint_to_uchar_ptr(unsigned int nb);

/*
** side_funct
*/
char				*read_from_fd(int fd);
void				u_char_copy(unsigned char *src, unsigned char *dst, size_t len);
unsigned long long	ft_pow(int nb, int pow);

#endif
