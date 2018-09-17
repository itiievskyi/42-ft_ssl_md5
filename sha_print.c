/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:41:27 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/17 14:41:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"

void		sha256_print(char *str, t_flags *flags, t_sha256_ctx *ctx)
{
	int				i;
	char			*ret;

	i = -1;
	if (!flags->q && !flags->r && !flags->p)
		ft_printf("SHA256 (%c%s%c) = ", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	ret = ft_itoa_hex(ctx->state, 64, 0, 'B');
	write(1, ret, 64);
	((!flags->q && !flags->r) || flags->q || flags->p) ? ft_printf("\n") : 0;
	if (!flags->q && flags->r && !flags->p)
		ft_printf(" %c%s%c\n", (flags->s ? '\"' : 0),
		(flags->s ? str : ctx->file), (flags->s ? '\"' : 0));
	flags->s ? 0 : free(str);
	free(ret);
}
