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
	flags->p == -2 ? 0 : ft_printf("%s", str);
	return (str);
}
