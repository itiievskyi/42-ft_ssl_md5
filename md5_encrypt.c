/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_encrypt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:26:02 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/07 09:26:07 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"

void		md5_print(char *str, t_flags *flags, t_md5_ctx *ctx)
{
	int				i;
	char			*ret;

	i = -1;
	if (!flags->q && !flags->r && !flags->p)
		ft_printf("MD5 (%c%s%c) = ", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	ret = ft_itoa_hex(ctx->state, 32, 0, 'L');
	write(1, ret, 32);
	((!flags->q && !flags->r) || flags->q || flags->p) ? ft_printf("\n") : 0;
	if (!flags->q && flags->r && !flags->p)
		ft_printf(" %c%s%c\n", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	flags->s ? 0 : free(str);
	free(ret);
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
		md5_transform((uint32_t *)(input + offset), ctx);
		offset += (512 / 8);
	}
}

int			md5_encrypt(char *str, t_flags *flags, t_md5_ctx *ctx)
{
	size_t			len;
	size_t			i;
	int				j;
	unsigned char	*input;

	if (!str || !flags || ++(ctx->targets) < 0 || !(i = -1))
		return (-1);
	j = -1;
	len = ctx->len * 8 + 1;
	while (len % 512 != 448)
		len++;
	len /= 8;
	if (!(input = (unsigned char*)malloc(sizeof(unsigned char) * (len + 8))))
		return (-1);
	while (++i < ctx->len)
		input[i] = str[i];
	input[i] = 128;
	while (++i < len)
		input[i] = 0;
	while (++i - 1 < len + 8 && (++j > -1))
		input[len + j] = (ctx->len * 8 >> (j * 8)) % 256;
	md5_process(input, len, ctx);
	md5_print(str, flags, ctx);
	free(input);
	return (1);
}
