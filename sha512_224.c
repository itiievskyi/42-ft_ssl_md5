/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_224.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:34:43 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/18 12:34:45 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha512.h"

void		sha512224_process(uint64_t **input, t_sha512_ctx *ctx)
{
	int		j;

	j = 0;
	ctx->state[0] = 0x8C3D37C819544DA2;
	ctx->state[1] = 0x73E1996689DCD4D6;
	ctx->state[2] = 0x1DFAB7AE32FF9C82;
	ctx->state[3] = 0x679DD514582F9FCF;
	ctx->state[4] = 0x0F6D2B697BD44DA8;
	ctx->state[5] = 0x77E36F7304C48942;
	ctx->state[6] = 0x3F9D85A86A1D36C8;
	ctx->state[7] = 0x1112E6AD91D692A1;
	while (j < ctx->blocks)
	{
		sha512_transform(input[j], ctx, -1, -1);
		j++;
	}
}

int			sha512224_encrypt(char *str, t_flags *flags, t_sha512_ctx *ctx)
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
	sha512224_process(input, ctx);
	sha512224_print(str, flags, ctx);
	i = -1;
	while (++i < ctx->blocks)
		free(input[i]);
	free(input);
	return (1);
}

int			sha512224_choose_target(char **argv, t_flags *flags, int i,
			t_sha512_ctx *ctx)
{
	int		j;

	j = 0;
	while (argv[i][++j])
	{
		check_extra_flags(flags, argv[i][j], ctx->func);
		if (argv[i][j] == 's' && (flags->s = 1) && argv[i][j + 1]
		&& (ctx->len = ft_strlen(&argv[i][j + 1])) < MAX &&
		sha512224_encrypt(&argv[i][j + 1], flags, ctx) > 0)
			return (i);
		else if (argv[i][j] == 's' && i + 1 >= ctx->argc)
			ssl_s_error(flags, ctx->func);
		else if (argv[i][j] == 's' && (ctx->len = ft_strlen(argv[i + 1])) < MAX
		&& sha512224_encrypt(argv[i + 1], flags, ctx) > 0)
			return (i + 1);
		else if (argv[i][j] == 'p' && ++(flags->p) && ++(flags->stdin))
		{
			sha512224_encrypt(ssl_read_stdin(&ctx->len, 0, flags), flags, ctx);
			if (argv[i][j + 1] == '\0')
				return (i);
			flags_init(flags);
		}
	}
	return (i);
}

void		sha512224_parse_targets(int argc, char **argv, t_flags *flags,
			t_sha512_ctx *ctx)
{
	int		j;
	int		i;
	int		fd;

	i = 1;
	while (++i < argc && ((j = 0) == 0) && !flags->nomore && flags_init(flags))
	{
		if (argv[i][0] == '-' && !flags->nomore)
			i = sha512224_choose_target(argv, flags, i, ctx);
		else
			flags->nomore = 1;
	}
	if (!flags->p)
		i = ((flags->s) ? i - 1 : i - 2);
	flags_init(flags);
	while (++i < argc && i > 1 && flags->nomore == 1)
	{
		if ((((fd = open(argv[i], O_WRONLY)) < 0 && errno == EISDIR) ||
		(fd = open(argv[i], O_RDONLY)) < 0) && ++(ctx->targets))
			ft_printf("ft_ssl: %s: %s: %s\n", ctx->func, argv[i],
			strerror(errno));
		else
			sha512224_encrypt(ssl_read_file(
			argv[i], &ctx->len, ctx->func, &ctx->file), flags, ctx);
	}
}

void		sha512224(int argc, char **argv)
{
	t_flags			*flags;
	t_sha512_ctx	ctx;

	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return ;
	flags->nomore = 0;
	flags->p = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	flags->stdin = 0;
	ctx.argc = argc;
	ctx.targets = 0;
	ft_memcpy(ctx.func, "sha512224\0", 10);
	sha512224_parse_targets(argc, argv, flags, &ctx);
	if (ctx.targets == 0 || ((flags->stdin == ctx.targets) &&
	(flags->q || flags->r)))
	{
		flags_init(flags);
		(flags->p) = -2;
		++(flags->stdin);
		sha512224_encrypt(ssl_read_stdin(&ctx.len, 0, flags), flags, &ctx);
	}
	free(flags);
}
