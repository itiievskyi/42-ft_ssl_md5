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

char		*read_file(char *arg, int fd, int length)
{
	char	*str;
	char	ch;
	int		i;

	i = 0;
	str = NULL;
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_printf("ft_ssl: md5: %s: %s\n", arg, strerror(errno));
	else
	{
		while (read(fd, &ch, 1) > 0)
			length++;
		str = (char*)malloc(sizeof(char) * i + 1);
		close(fd);
		fd = open(arg, O_RDONLY);
		while (read(fd, &ch, 1) > 0)
		{
			str[i++] = ch;
		}
		str[i] = '\0';
	}
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

	while (++i < argc && ((j = 0) == 0) && !flags->nomore)
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
				if (argv[i][j] == 's' && (flags->s = 1) && argv[i][j + 1])
				{
					md5_encrypt(&argv[i][j + 1], flags);
					break ;
				}
				else if (argv[i][j] == 's' && i + 1 >= argc)
					md5_s_error(flags);
				else if (argv[i][j] == 's')
				{
					md5_encrypt(argv[i + 1], flags);
					i++;
					break ;
				}
				else if (argv[i][j] == 'p')
					md5_encrypt(read_stdin(), flags);
			}
		}
		else
			flags->nomore = 1;
	}
	i = (flags->s ? i - 1 : i - 2);
	flags_init(flags);
	while (++i < argc && i > 1)
		md5_encrypt(read_file(argv[i], 0, i), flags);
}

void		md5(int argc, char **argv, int i)
{
	t_flags			*flags;
//	unsigned char	*input;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->nomore = 0;
	flags->p = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	parse_targets(argc, argv, i, flags);
}
