/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_encrypt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:17:39 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/17 16:17:41 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha512.h"

void		sha512_abcd_assign(t_sha512_ctx *ctx, char order)
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

void		sha512_transform(uint64_t *input, t_sha512_ctx *ctx, int i, int rnd)
{
	uint64_t	t1;
	uint64_t	t2;
	uint64_t	w[80];

	while (++i < 16)
		w[i] = input[i];
	i -= 1;
	while (++i < 80)
		w[i] = w[i - 16] + S0(w[i - 15]) + w[i - 7] + S1(w[i - 2]);
	sha512_abcd_assign(ctx, '<');
	while (++rnd < 80)
	{
		t1 = ctx->h + E1(ctx->e) + CH(ctx->e, ctx->f, ctx->g)
			+ g_words64[rnd] + w[rnd];
		t2 = E0(ctx->a) + MAJ(ctx->a, ctx->b, ctx->c);
		ctx->h = ctx->g;
		ctx->g = ctx->f;
		ctx->f = ctx->e;
		ctx->e = ctx->d + t1;
		ctx->d = ctx->c;
		ctx->c = ctx->b;
		ctx->b = ctx->a;
		ctx->a = t1 + t2;
	}
	sha512_abcd_assign(ctx, '>');
}

void		sha512_process(uint64_t **input, t_sha512_ctx *ctx)
{
	int		j;

	j = 0;
	ctx->state[0] = 0x6a09e667f3bcc908;
	ctx->state[1] = 0xbb67ae8584caa73b;
	ctx->state[2] = 0x3c6ef372fe94f82b;
	ctx->state[3] = 0xa54ff53a5f1d36f1;
	ctx->state[4] = 0x510e527fade682d1;
	ctx->state[5] = 0x9b05688c2b3e6c1f;
	ctx->state[6] = 0x1f83d9abfb41bd6b;
	ctx->state[7] = 0x5be0cd19137e2179;
	while (j < ctx->blocks)
	{
		sha512_transform(input[j], ctx, -1, -1);
		j++;
	}
}

void		sha512_finalize(char *str, uint64_t **input, t_sha512_ctx *ctx)
{
	int			i;
	size_t		n;
	int			u;

	n = 0;
	i = 0;
	u = 56;
	while (n < ctx->len)
	{
		u = (n % 8 == 0 ? 56 : u - 8);
		input[i][n % 128 / 8] |= (((uint64_t)str[n] << u) &
			(0xffffffffffffffff >> (((n) % 8)) * 8));
		(((++n) % 128)) == 0 ? i++ : 0;
	}
	u = (n % 8 == 0 ? 56 : u - 8);
	input[i][(n) % 128 / 8] |= (uint64_t)0x80 << u;
	input[ctx->blocks - 1][14] = ((uint64_t)ctx->len * 8) >> 56;
	input[ctx->blocks - 1][15] = ((uint64_t)ctx->len * 8) & 0xffffffffffffffff;
}

int			sha512_encrypt(char *str, t_flags *flags, t_sha512_ctx *ctx)
{
	int			i;
	uint64_t	len;
	uint64_t	**input;

	if (!str || !flags || ++(ctx->targets) < 0)
		return (-1);
	i = -1;
	len = ctx->len * 8 + 1;
	while (len % 1024 != 896)
		len++;
	ctx->blocks = (len += 128) / 1024;
	input = (uint64_t**)malloc(sizeof(uint64_t*) * ctx->blocks);
	while (++i < ctx->blocks)
	{
		input[i] = (uint64_t*)malloc(sizeof(uint64_t) * 16);
		ft_bzero(input[i], sizeof(uint64_t) * 16);
	}
	sha512_finalize(str, input, ctx);
	sha512_process(input, ctx);
	sha512_print(str, flags, ctx);
	i = -1;
	while (++i < ctx->blocks)
		free(input[i]);
	free(input);
	return (1);
}
