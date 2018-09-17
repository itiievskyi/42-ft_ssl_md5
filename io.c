/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:23:26 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/28 16:23:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		check_extra_flags(t_flags *flags, char flag, char f[])
{
	!ft_strchr(FLAGS, flag) ? ssl_err_flag(flag, flags, f) : 0;
	(flag == 'q') ? flags->q = 1 : 0;
	(flag == 'r' && !flags->q) ? flags->r = 1 : 0;
}

char		*ssl_read_file(char *arg, size_t *length, char f[], char **file)
{
	char	*str;
	char	ch;
	int		fd;
	size_t	i;

	str = NULL;
	i = 0;
	if (((fd = open(arg, O_WRONLY)) < 0 && errno == EISDIR) ||
	(fd = open(arg, O_RDONLY)) < 0)
		ft_printf("ft_ssl: %s: %s: %s\n", f, arg, strerror(errno));
	else
	{
		while (read(fd, &ch, 1) > 0)
			i++;
		close(fd);
		str = (char*)malloc(sizeof(char) * (i + 1));
		(fd = open(arg, O_RDONLY)) > 0 ?
			i = 0 : 0;
		while (read(fd, &ch, 1) > 0)
			str[i++] = ch;
		str[i] = '\0';
		*length = i;
		*file = arg;
	}
	return (str);
}

char		*ssl_finish_stdin(size_t *len, int i, char *str, char *buf)
{
	char	*ret;

	ret = ft_strjoin_size(str, buf, i);
	buf ? free(buf) : 0;
	str ? free(str) : 0;
	*len = (i <= 0 ? 0 : i);
	return (ret);
}

char		*ssl_read_stdin(size_t *len, int i, t_flags *flags)
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
				str = ft_strjoin_size(temp, buf, i);
				temp ? free(temp) : 0;
				buf ? free(buf) : 0;
				buf = ft_strnew(BUF);
			}
			buf[i++ % BUF] = ch;
		}
	}
	str = ssl_finish_stdin(len, i, str, buf);
	flags->p == -2 ? 0 : write(1, str, i);
	return (str);
}
