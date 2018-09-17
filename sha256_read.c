/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:25:01 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/07 09:25:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"

int			sha256_choose_target(char **argv, t_flags *flags, int i,
			t_sha256_ctx *ctx)
{
	int		j;

	j = 0;
	while (argv[i][++j])
	{
		check_extra_flags(flags, argv[i][j], ctx->func);
		if (argv[i][j] == 's' && (flags->s = 1) && argv[i][j + 1]
		&& (ctx->len = ft_strlen(&argv[i][j + 1])) < MAX &&
		sha256_encrypt(&argv[i][j + 1], flags, ctx) > 0)
			return (i);
		else if (argv[i][j] == 's' && i + 1 >= ctx->argc)
			ssl_s_error(flags, ctx->func);
		else if (argv[i][j] == 's' && (ctx->len = ft_strlen(argv[i + 1])) < MAX
		&& sha256_encrypt(argv[i + 1], flags, ctx) > 0)
			return (i + 1);
		else if (argv[i][j] == 'p' && ++(flags->p) && ++(flags->stdin))
		{
			sha256_encrypt(ssl_read_stdin(&ctx->len, 0, flags), flags, ctx);
			if (argv[i][j + 1] == '\0')
				return (i);
			flags_init(flags);
		}
	}
	return (i);
}

void		sha256_parse_targets(int argc, char **argv, t_flags *flags,
			t_sha256_ctx *ctx)
{
	int		j;
	int		i;
	int		fd;

	i = 1;
	while (++i < argc && ((j = 0) == 0) && !flags->nomore && flags_init(flags))
	{
		if (argv[i][0] == '-' && !flags->nomore)
			i = sha256_choose_target(argv, flags, i, ctx);
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
			sha256_encrypt(ssl_read_file(
			argv[i], &ctx->len, ctx->func, &ctx->file), flags, ctx);
	}
}

void		sha256(int argc, char **argv)
{
	t_flags			*flags;
	t_sha256_ctx	ctx;

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
	ft_memcpy(ctx.func, "sha256\0\0\0\0", 10);
	sha256_parse_targets(argc, argv, flags, &ctx);
	if (ctx.targets == 0 || ((flags->stdin == ctx.targets) &&
	(flags->q || flags->r)))
	{
		flags_init(flags);
		(flags->p) = -2;
		++(flags->stdin);
		sha256_encrypt(ssl_read_stdin(&ctx.len, 0, flags), flags, &ctx);
	}
	free(flags);
}
