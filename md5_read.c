/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:23:26 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/28 16:23:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"

char		*md5_read_file(char *arg, int fd, int length, t_md5_ctx *ctx)
{
	char	*str;
	char	ch;
	int		i;

	i = 0;
	str = NULL;
	if (((fd = open(arg, O_WRONLY)) < 0 && errno == EISDIR) ||
	(fd = open(arg, O_RDONLY)) < 0)
		ft_printf("ft_ssl: md5: %s: %s\n", arg, strerror(errno));
	else
	{
		while (read(fd, &ch, 1) > 0)
			length++;
		str = (char*)malloc(sizeof(char) * (length + 1));
		close(fd);
		fd = open(arg, O_RDONLY);
		while (read(fd, &ch, 1) > 0)
			str[i++] = ch;
		str[i] = '\0';
		ctx->len = i;
		ctx->file = arg;
	}
	return (str);
}

int			md5_choose_target(char **argv, t_flags *flags, int i,
			t_md5_ctx *ctx)
{
	int		j;

	j = 0;
	while (argv[i][++j])
	{
		!ft_strchr(FLAGS, argv[i][j]) ? md5_err_flag(argv[i][j], flags) : 0;
		(argv[i][j] == 'q') ? flags->q = 1 : 0;
		(argv[i][j] == 'r' && !flags->q) ? flags->r = 1 : 0;
		if (argv[i][j] == 's' && (flags->s = 1) && argv[i][j + 1]
		&& (ctx->len = ft_strlen(&argv[i][j + 1])) < MAX)
		{
			md5_encrypt(&argv[i][j + 1], flags, ctx);
			return (i);
		}
		else if (argv[i][j] == 's' && i + 1 >= ctx->argc)
			md5_s_error(flags);
		else if (argv[i][j] == 's' && (ctx->len = ft_strlen(argv[i + 1])) < MAX)
		{
			md5_encrypt(argv[i + 1], flags, ctx);
			return (i + 1);
		}
		else if (argv[i][j] == 'p' && ++(flags->p) && ++(flags->stdin))
		{
			md5_encrypt(ssl_read_stdin(&ctx->len, 0, flags), flags, ctx);
			if (argv[i][j + 1] == '\0')
				return (i);
			flags_init(flags);
		}
	}
	return (i);
}

void		md5_parse_targets(int argc, char **argv, t_flags *flags,
			t_md5_ctx *ctx)
{
	int		j;
	int		i;

	i = 1;
	while (++i < argc && ((j = 0) == 0) && !flags->nomore)
	{
		flags_init(flags);
		if (argv[i][0] == '-' && !flags->nomore)
			i = md5_choose_target(argv, flags, i, ctx);
		else
			flags->nomore = 1;
	}
	if (!flags->p)
		i = ((flags->s) ? i - 1 : i - 2);
	flags_init(flags);
	while (++i < argc && i > 1 && flags->nomore == 1)
		md5_encrypt(md5_read_file(argv[i], 0, i, ctx), flags, ctx);
}

void		md5(int argc, char **argv)
{
	t_flags			*flags;
	t_md5_ctx		ctx;

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
	md5_parse_targets(argc, argv, flags, &ctx);
	if (ctx.targets == 0 || ((flags->stdin == ctx.targets) &&
	(flags->q || flags->r)))
	{
		flags_init(flags);
		(flags->p) = -2;
		++(flags->stdin);
		md5_encrypt(ssl_read_stdin(&ctx.len, 0, flags), flags, &ctx);
	}
	free(flags);
}
