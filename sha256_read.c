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


char		*sha256_read_file(char *arg, int fd, int length, t_sha256_ctx *ctx)
{
	char	*str;
	char	ch;
	int		i;

	i = 0;
	str = NULL;
	if ((fd = open(arg, O_RDONLY)) < 0 ||
	((fd = open(arg, O_WRONLY)) < 0 && errno == EISDIR))
		ft_printf("ft_ssl: sha256: %s: %s\n", arg, strerror(errno));
	else
	{
		while (read(fd, &ch, 1) > 0)
			length++;
		str = (char*)malloc(sizeof(char) * i + 1);
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

char		*sha256_read_stdin(t_sha256_ctx *ctx, int i, t_flags *flags)
{
	char	*buf;
	char	*temp;
	char	*str;
	char	ch;

	str = NULL;
	buf = ft_strnew(BUF);
	if (flags->stdin == 1)
	{
		while (read(0, &ch, 1) > 0)
		{
			if ((i) % BUF == 0 && i > 0)
			{
				temp = str;
				str = ft_strjoin(temp, buf);
				temp ? free(temp) : 0;
				buf ? free(buf) : 0;
				buf = ft_strnew(BUF);
			}
			buf[i % BUF] = ch;
			i++;
		}
	}
	str = ft_strjoin(str, buf);
	buf ? free(buf) : 0;
	ft_printf("%s", str);
	ctx->len = (i <= 0 ? 0 : i);
	return (str);
}

int			sha256_choose_target(char **argv, t_flags *flags, int i,
			t_sha256_ctx *ctx)
{
	int		j;

	j = 0;
	while (argv[i][++j])
	{
		!ft_strchr(FLAGS, argv[i][j]) ? sha256_err_flag(argv[i][j], flags) : 0;
		argv[i][j] == 'q' ? flags->q = 1 : 0;
		(argv[i][j] == 'r' && !flags->q) ? flags->r = 1 : 0;
		if (argv[i][j] == 's' && (flags->s = 1) && argv[i][j + 1]
		&& (ctx->len = ft_strlen(&argv[i][j + 1])) < MAX)
		{
			sha256_encrypt(&argv[i][j + 1], flags, ctx);
			return (i);
		}
		else if (argv[i][j] == 's' && i + 1 >= ctx->argc)
			sha256_s_error(flags);
		else if (argv[i][j] == 's' && (ctx->len = ft_strlen(argv[i + 1])) < MAX)
		{
			sha256_encrypt(argv[i + 1], flags, ctx);
			return (i + 1);
		}
		else if (argv[i][j] == 'p' && ++(flags->p) && ++(flags->stdin))
		{
			sha256_encrypt(sha256_read_stdin(ctx, 0, flags), flags, ctx);
			return (i);
		}
	}
	return (i);
}

void		sha256_parse_targets(int argc, char **argv, t_flags *flags,
			t_sha256_ctx *ctx)
{
	int		j;
	int		i;

	i = 1;
	while (++i < argc && ((j = 0) == 0) && !flags->nomore)
	{
		flags_init(flags);
		if (argv[i][0] == '-' && !flags->nomore)
			i = sha256_choose_target(argv, flags, i, ctx);
		else
			flags->nomore = 1;
	}
	if (!flags->p)
		i = ((flags->s) ? i - 1 : i - 2);
	flags_init(flags);
	while (++i < argc && i > 1)
		sha256_encrypt(sha256_read_file(argv[i], 0, i, ctx), flags, ctx);
}

void		sha256(int argc, char **argv)
{
	t_flags			*flags;
	t_sha256_ctx		ctx;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->nomore = 0;
	flags->p = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	flags->stdin = 0;
	ctx.argc = argc;
	sha256_parse_targets(argc, argv, flags, &ctx);
}
