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

void		md5_print(char *str, t_flags *flags, t_md5_ctx *ctx)
{
	uint8_t		*p;

	if (!flags->q && !flags->r && !flags->p)
		ft_printf("MD5 (%c%s%c) = ", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	p = (uint8_t *)&ctx->state[0];
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&ctx->state[1];
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&ctx->state[2];
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	p = (uint8_t *)&ctx->state[3];
	ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	((!flags->q && !flags->r) || flags->q || flags->p) ? ft_printf("\n") : 0;
	if (!flags->q && flags->r && !flags->p)
		ft_printf(" %c%s%c\n", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
}

void		md5_abcd_assign(t_md5_ctx *ctx, char order)
{
	if (order == '<')
	{
		ctx->a = ctx->state[0];
		ctx->b = ctx->state[1];
		ctx->c = ctx->state[2];
		ctx->d = ctx->state[3];
	}
	else if (order == '>')
	{
		ctx->state[0] += ctx->a;
		ctx->state[1] += ctx->b;
		ctx->state[2] += ctx->c;
		ctx->state[3] += ctx->d;
	}
}

void		md5_transform(uint32_t *w, t_md5_ctx *ctx)
{
	uint32_t i;
	uint32_t f;
	uint32_t temp;

	i = -1;
	md5_abcd_assign(ctx, '<');
	while (++i < 64)
	{
		if (i < 16)
			f = (ctx->b & ctx->c) | ((~ctx->b) & ctx->d);
		else if (i < 32)
			f = (ctx->d & ctx->b) | ((~ctx->d) & ctx->c);
		else if (i < 48)
			f = ctx->b ^ ctx->c ^ ctx->d;
		else
			f = ctx->c ^ (ctx->b | (~ctx->d));
		temp = ctx->d;
		ctx->d = ctx->c;
		ctx->c = ctx->b;
		ctx->b = ctx->b + RL((ctx->a + f + g_words[i] + w[g_x[i]]), g_s[i]);
		ctx->a = temp;
	}
	md5_abcd_assign(ctx, '>');
}

void		md5_process(unsigned char *input, int len, t_md5_ctx *ctx)
{
	int			offset;

	offset = 0;
	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xefcdab89;
	ctx->state[2] = 0x98badcfe;
	ctx->state[3] = 0x10325476;
	while (offset < len)
	{
		md5_transform((uint32_t *) (input + offset), ctx);
		offset += (512 / 8);
	}
}

void		md5_encrypt(char *str, t_flags *flags, t_md5_ctx *ctx)
{
	size_t			len;
	size_t			i;
	int				j;
	unsigned char	*input;

	if (!str || !flags)
		return ;
	i = -1;
	j = -1;
	for(len = ctx->len * 8 + 1; len % 512!=448; len++);
	len /= 8;
	input = (unsigned char*)malloc(sizeof(unsigned char) * (len + 8));
	while (++i < ctx->len)
		input[i] = str[i];
	input[i] = 128;
	while (++i < len)
		input[i] = 0;
	while (++i - 1 < len + 8 && (++j > -1))
		input[len + j] = (ctx->len * 8 >> (j * 8)) % 256;
	md5_process(input, len, ctx);
	md5_print(str, flags, ctx);

	/* CHECKING */

//	ft_printf("%s\n", str);
/*	int y;
	size_t z = -1;
	while (++z < len / 8) {
		for (y = 0; y < 8; y++) {
			ft_printf("%d", !!((input[z] << y) & 0x80));
		}
		ft_printf(" ");
	}
	ft_printf("\n");
*///for(int j =0; j < 64; j++) ft_printf("%x ", ((uint8_t *) input)[j]);
//	ft_printf("\nstr_len = %d bytes, length = %d bits, or %d bytes\n", ctx->len, len, len / 8);

}
