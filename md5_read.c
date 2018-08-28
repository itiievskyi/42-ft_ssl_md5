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

char		*read_file(char *arg, int fd)
{
	char	*str = NULL;
	ft_printf("%s\n", "dsfasdfas");

	if (!(fd = open(arg, O_RDONLY)))
		ft_printf("%s", strerror(errno));
	if (arg) {}
	return (str);
}

char		*read_stdin(void)
{
	char	*str = NULL;

	return (str);
}

void		parse_targets(int argc, char **argv, int i, t_flags *flags)
{
	int		j;

	while (++i < argc && ((j = 0) == 0))
	{
		flags_init(flags);
		if (argv[i][j] == '-' && !flags->nomore)
		{
			while (argv[i][++j])
			{
				!ft_strchr(FLAGS, argv[i][j]) ?
					md5_err_flag(argv[i][j], flags) : 0;
				argv[i][j] == 'q' ? flags->q = 1 : 0;
				(argv[i][j] == 'r' && !flags->q) ? flags->r = 1 : 0;
				if (argv[i][j] == 's' && argv[i][j + 1] != '\0')
				{
					md5_encrypt(&argv[i][j + 1], flags);
					break ;
				}
				else if (argv[i][j] == 's' && i + 1 >= argc)
					md5_s_error(flags);
				else if (argv[i][j] == 's')
				{
					md5_encrypt(&argv[i][j + 1] flags);
					i++;
					break ;
				}
				else if (argv[i][j] == 'p')
					md5_encrypt(read_stdin(), flags);
			}
		}
	}
	while (i < argc)
		md5_encrypt(read_file(argv[i], 0), flags);
}

void		md5(int argc, char **argv, int i)
{
	t_flags		*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->nomore = 0;
	flags->p = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	parse_targets(argc, argv, i, flags);
}
