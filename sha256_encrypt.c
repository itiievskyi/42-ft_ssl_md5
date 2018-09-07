/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_encrypt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:25:12 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/07 09:25:14 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"

void		sha256_print(char *str, t_flags *flags, t_sha256_ctx *ctx)
{
	uint8_t		*p;
	int			i;

	i = -1;
	if (!flags->q && !flags->r && !flags->p)
		ft_printf("SHA256 (%c%s%c) = ", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	while (++i < 8)
	{
		p = (uint8_t *)&ctx->state[i];
		ft_printf("%2.2x%2.2x%2.2x%2.2x", p[0], p[1], p[2], p[3]);
	}
	((!flags->q && !flags->r) || flags->q || flags->p) ? ft_printf("\n") : 0;
	if (!flags->q && flags->r && !flags->p)
		ft_printf(" %c%s%c\n", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
}

void		sha256_abcd_assign(t_sha256_ctx *ctx, char order)
{
	if (order == '<')
	{
		ctx->a = ctx->state[0];
		ctx->b = ctx->state[1];
		ctx->c = ctx->state[2];
		ctx->d = ctx->state[3];
		ctx->e = ctx->state[4];
		ctx->f = ctx->state[5];
		ctx->g = ctx->state[6];
		ctx->h = ctx->state[7];
	}
	else if (order == '>')
	{
		ctx->state[0] += ctx->a;
		ctx->state[1] += ctx->b;
		ctx->state[2] += ctx->c;
		ctx->state[3] += ctx->d;
		ctx->state[4] += ctx->e;
		ctx->state[5] += ctx->f;
		ctx->state[6] += ctx->g;
		ctx->state[7] += ctx->h;
	}
}

void		sha256_transform(uint32_t *data, t_sha256_ctx *ctx)
{
	uint32_t i;
	uint32_t t1;
	uint32_t t2;
	uint32_t w[64];

	for(i=0; i<16; i++) {
		w[i] = data[i];
	}
	for(i=16; i<64; i++)
		w[i] = w[i-16] + S0(w[i-15]) + w[i-7] + S1(w[i-2]);
	i = -1;
	sha256_abcd_assign(ctx, '<');

	for (i = 0; i < 64; ++i) {
		t1 = ctx->h + E1(ctx->e) + CH(ctx->e,ctx->f,ctx->g) + k[i] + w[i];
		t2 = E0(ctx->a) + MAJ(ctx->a,ctx->b,ctx->c);
		ctx->h = ctx->g;
		ctx->g = ctx->f;
		ctx->f = ctx->e;
		ctx->e = ctx->d + t1;
		ctx->d = ctx->c;
		ctx->c = ctx->b;
		ctx->b = ctx->a;
		ctx->a = t1 + t2;
	}
	sha256_abcd_assign(ctx, '>');
}

void		sha256_process(unsigned char *input, int len, t_sha256_ctx *ctx)
{
	int			offset;

	offset = 0;
	ctx->state[0] = 0x6a09e667;
	ctx->state[1] = 0xbb67ae85;
	ctx->state[2] = 0x3c6ef372;
	ctx->state[3] = 0xa54ff53a;
	ctx->state[4] = 0x510e527f;
	ctx->state[5] = 0x9b05688c;
	ctx->state[6] = 0x1f83d9ab;
	ctx->state[7] = 0x5be0cd19;
	while (offset < len)
	{
		sha256_transform((uint32_t *) (input + offset), ctx);
		offset += (512 / 8);
	}
}

void		sha256_encrypt(char *str, t_flags *flags, t_sha256_ctx *ctx)
{
	size_t			len;
	size_t			i;
	int				j;
	unsigned char	*input;

	if (!str || !flags)
		return ;
	i = -1;
	j = -1;
	for(len = ctx->len * 8 + 1; len % 512 != 448; len++);
	len /= 8;
	input = (unsigned char*)malloc(sizeof(unsigned char) * (len + 8));
	while (++i < ctx->len)
		input[i] = str[i];
	input[i] = 128;
	while (++i < len)
		input[i] = 0;
	while ((++j) < 8)
		input[len + 8 - j - 1] = (ctx->len * 8 >> (j * 8)) % 256;
	sha256_process(input, len, ctx);
	sha256_print(str, flags, ctx);

	/* CHECKING */

//	ft_printf("%s\n", str);
/*	int y;
	size_t z = -1;
	while (++z < len + 8) {
		for (y = 0; y < 8; y++) {
			ft_printf("%d", !!((input[z] << y) & 0x80));
		}
		ft_printf(" ");
	}
	ft_printf("\n");
*/for(int j =0; j < 64; j++) ft_printf("%x ", ((uint8_t *) input)[j]);
//	ft_printf("\nstr_len = %d bytes, length = %d bits, or %d bytes\n", ctx->len, len, len / 8);

}
