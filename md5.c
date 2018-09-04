/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:16:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/24 17:16:33 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"

void		md5_transform(uint32_t *w, t_md5_ctx *ctx)
{
//	if (w && ctx.state[0]) {}
	uint32_t a = ctx->state[0];
	uint32_t b = ctx->state[1];
	uint32_t c = ctx->state[2];
	uint32_t d = ctx->state[3];

	uint32_t i;
	for(i = 0; i<64; i++) {
		uint32_t f, g;
		 if (i < 16) {
			f = (b & c) | ((~b) & d);
			g = i;
		} else if (i < 32) {
			f = (d & b) | ((~d) & c);
			g = (5*i + 1) % 16;
		} else if (i < 48) {
			f = b ^ c ^ d;
			g = (3*i + 5) % 16;
		} else {
			f = c ^ (b | (~d));
			g = (7*i) % 16;
		}
		uint32_t temp = d;
		d = c;
		c = b;
		b = b + RL((a + f + g_words[i] + w[g]), g_s[i]);
		a = temp;
	}
	ctx->state[0] += a;
	ctx->state[1] += b;
	ctx->state[2] += c;
	ctx->state[3] += d;
}

void		md5_process(unsigned char *input, int len)
{
	t_md5_ctx	ctx;
	int			offset;

	offset = 0;
	ctx.count[0] = 0;
	ctx.count[1] = 0;
	ctx.state[0] = 0x67452301;
	ctx.state[1] = 0xefcdab89;
	ctx.state[2] = 0x98badcfe;
	ctx.state[3] = 0x10325476;

	while (offset < len)
	{
		md5_transform((uint32_t *) (input + offset), &ctx);
		offset += (512 / 8);
    }
	uint8_t *p;
    p=(uint8_t *)&ctx.state[0];
    ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], ctx.state[0]);
    p=(uint8_t *)&ctx.state[1];
    ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], ctx.state[1]);
    p=(uint8_t *)&ctx.state[2];
    ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], ctx.state[2]);
    p=(uint8_t *)&ctx.state[3];
    ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3], ctx.state[3]);
	ft_printf("\n");
}

void		md5_encrypt(char *str, t_flags *flags)
{
	size_t			len;
	size_t			str_len;
	size_t			i;
	int				j;
	unsigned char	*input;

	if (!str || !flags)
		return ;
	i = -1;
	j = -1;
	str_len = ft_strlen(str);
    for(len = str_len*8 + 1; len % 512!=448; len++);
    len /= 8;
	input = (unsigned char*)malloc(sizeof(unsigned char) * (len + 8));
	while (++i < str_len)
		input[i] = str[i];
	input[i] = 128;
	while (++i < len)
		input[i] = 0;
	while (++i - 1 < len + 8 && (++j > -1))
		input[len + j] = (str_len * 8 >> (j * 8)) % 256;
	md5_process(input, len);

	/* CHECKING */
/*
//	ft_printf("%s\n", str);
	int y;
	size_t z = -1;
	while (++z < len / 8) {
		for (y = 0; y < 8; y++) {
			ft_printf("%d", !!((input[z] << y) & 0x80));
		}
		ft_printf(" ");
	}
	ft_printf("\n");
	for(int j =0; j < 64; j++) ft_printf("%x ", ((uint8_t *) input)[j]);
	ft_printf("\nstr_len = %d bytes, length = %d bits, or %d bytes\n", str_len, len, len / 8);
*/
}
