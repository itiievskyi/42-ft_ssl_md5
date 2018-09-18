/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:27:22 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/18 11:27:23 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha512.h"

void		sha512_print(char *str, t_flags *flags, t_sha512_ctx *ctx)
{
	int				i;
	char			*ret;

	i = -1;
	if (!flags->q && !flags->r && !flags->p)
		ft_printf("SHA512 (%c%s%c) = ", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	ret = ft_itoa_hex_512(ctx->state, 128, 0, 'B');
	write(1, ret, 128);
	((!flags->q && !flags->r) || flags->q || flags->p) ? ft_printf("\n") : 0;
	if (!flags->q && flags->r && !flags->p)
		ft_printf(" %c%s%c\n", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	flags->s ? 0 : free(str);
	free(ret);
}

void		sha384_print(char *str, t_flags *flags, t_sha512_ctx *ctx)
{
	int				i;
	char			*ret;

	i = -1;
	if (!flags->q && !flags->r && !flags->p)
		ft_printf("SHA384 (%c%s%c) = ", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	ret = ft_itoa_hex_512(ctx->state, 96, 0, 'B');
	write(1, ret, 96);
	((!flags->q && !flags->r) || flags->q || flags->p) ? ft_printf("\n") : 0;
	if (!flags->q && flags->r && !flags->p)
		ft_printf(" %c%s%c\n", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	flags->s ? 0 : free(str);
	free(ret);
}

void		sha512224_print(char *str, t_flags *flags, t_sha512_ctx *ctx)
{
	int				i;
	char			*ret;

	i = -1;
	if (!flags->q && !flags->r && !flags->p)
		ft_printf("SHA512/224 (%c%s%c) = ", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	ret = ft_itoa_hex_512(ctx->state, 56, 0, 'B');
	write(1, ret, 56);
	((!flags->q && !flags->r) || flags->q || flags->p) ? ft_printf("\n") : 0;
	if (!flags->q && flags->r && !flags->p)
		ft_printf(" %c%s%c\n", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	flags->s ? 0 : free(str);
	free(ret);
}

void		sha512256_print(char *str, t_flags *flags, t_sha512_ctx *ctx)
{
	int				i;
	char			*ret;

	i = -1;
	if (!flags->q && !flags->r && !flags->p)
		ft_printf("SHA512/256 (%c%s%c) = ", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	ret = ft_itoa_hex_512(ctx->state, 64, 0, 'B');
	write(1, ret, 64);
	((!flags->q && !flags->r) || flags->q || flags->p) ? ft_printf("\n") : 0;
	if (!flags->q && flags->r && !flags->p)
		ft_printf(" %c%s%c\n", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	flags->s ? 0 : free(str);
	free(ret);
}
