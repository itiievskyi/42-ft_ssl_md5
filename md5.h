/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:38:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/03 14:38:53 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H

#define RL(x, c) (((x) << (c)) | ((x) >> (32 - (c))))

# define F(x, y, z) ((x & y) | (~x & z))
# define G(x, y, z) ((x & z) | (y & ~z))
# define H(x, y, z) (x ^ y ^ z)
# define I(x, y, z) (y ^ (x | ~z))

# define FF(a, b, c, d, x, s, w) { a += F(b, c, d) + x + w; a = b + RL(a, s); }
# define GG(a, b, c, d, x, s, w) { a += G(b, c, d) + x + w; a = b + RL(a, s); }
# define HH(a, b, c, d, x, s, w) { a += H(b, c, d) + x + w; a = b + RL(a, s); }
# define II(a, b, c, d, x, s, w) { a += I(b, c, d) + x + w; a = b + RL(a, s); }

typedef struct				s_md5_ctx
{
	uint32_t				state[4];
	uint32_t				count[2];
	uint32_t				a;
	uint32_t				b;
	uint32_t				c;
	uint32_t				d;
	size_t					len;
	int						argc;
}							t_md5_ctx;

static uint32_t	g_words[64] =
{
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
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static uint32_t	g_x[64] =
{
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
	1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12,
	5, 8, 11, 14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2,
	0, 7, 14, 5, 12, 3, 10, 1, 8, 15, 6, 13, 4, 11, 2, 9
};

static uint32_t	g_s[64] =
{	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

void						flags_init(t_flags *flags);
void						md5_s_error(t_flags *flags);
void						md5_err_flag(char ch, t_flags *flags);
void						md5_encrypt(char *str, t_flags *flags,
							t_md5_ctx *ctx);
void						parse_targets(int argc, char **argv,
							t_flags *flags, t_md5_ctx *ctx);

#endif
