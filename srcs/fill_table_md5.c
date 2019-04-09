/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table_md5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:52:53 by tholzheu          #+#    #+#             */
/*   Updated: 2019/04/08 21:11:13 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void		fill_table_3(unsigned int table[64])
{
	table[48] = 0xf4292244;
	table[49] = 0x432aff97;
	table[50] = 0xab9423a7;
	table[51] = 0xfc93a039;
	table[52] = 0x655b59c3;
	table[53] = 0x8f0ccc92;
	table[54] = 0xffeff47d;
	table[55] = 0x85845dd1;
	table[56] = 0x6fa87e4f;
	table[57] = 0xfe2ce6e0;
	table[58] = 0xa3014314;
	table[59] = 0x4e0811a1;
	table[60] = 0xf7537e82;
	table[61] = 0xbd3af235;
	table[62] = 0x2ad7d2bb;
	table[63] = 0xeb86d391;
}

static void		fill_table_2(unsigned int table[64])
{
	table[24] = 0x21e1cde6;
	table[25] = 0xc33707d6;
	table[26] = 0xf4d50d87;
	table[27] = 0x455a14ed;
	table[28] = 0xa9e3e905;
	table[29] = 0xfcefa3f8;
	table[30] = 0x676f02d9;
	table[31] = 0x8d2a4c8a;
	table[32] = 0xfffa3942;
	table[33] = 0x8771f681;
	table[34] = 0x6d9d6122;
	table[35] = 0xfde5380c;
	table[36] = 0xa4beea44;
	table[37] = 0x4bdecfa9;
	table[38] = 0xf6bb4b60;
	table[39] = 0xbebfbc70;
	table[40] = 0x289b7ec6;
	table[41] = 0xeaa127fa;
	table[42] = 0xd4ef3085;
	table[43] = 0x04881d05;
	table[44] = 0xd9d4d039;
	table[45] = 0xe6db99e5;
	table[46] = 0x1fa27cf8;
	table[47] = 0xc4ac5665;
	fill_table_3(table);
}

void			fill_table(unsigned int table[64])
{
	table[0] = 0xd76aa478;
	table[1] = 0xe8c7b756;
	table[2] = 0x242070db;
	table[3] = 0xc1bdceee;
	table[4] = 0xf57c0faf;
	table[5] = 0x4787c62a;
	table[6] = 0xa8304613;
	table[7] = 0xfd469501;
	table[8] = 0x698098d8;
	table[9] = 0x8b44f7af;
	table[10] = 0xffff5bb1;
	table[11] = 0x895cd7be;
	table[12] = 0x6b901122;
	table[13] = 0xfd987193;
	table[14] = 0xa679438e;
	table[15] = 0x49b40821;
	table[16] = 0xf61e2562;
	table[17] = 0xc040b340;
	table[18] = 0x265e5a51;
	table[19] = 0xe9b6c7aa;
	table[20] = 0xd62f105d;
	table[21] = 0x02441453;
	table[22] = 0xd8a1e681;
	table[23] = 0xe7d3fbc8;
	fill_table_2(table);
}
