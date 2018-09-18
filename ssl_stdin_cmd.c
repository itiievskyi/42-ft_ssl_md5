/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_stdin_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:44:33 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/18 16:44:35 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	stdin_parse_handler(int argc, char **argv, t_ssl_func handler[],
		bool *no_error)
{
	int		i;

	i = 0;
	while (argv[i++])
		argc++;
	argc == 1 ? usage() : 0;
	i = 0;
	init_functions(handler);
	while (i < FUNCTIONS)
	{
		if (ft_strequ(argv[1], handler[i].func))
		{
			handler[i].handler(argc, argv);
			*no_error = true;
		}
		i++;
	}
}

void	stdin_cmd(int argc, int i, t_ssl_func handler[], bool no_error)
{
	char	*str;
	char	**argv;
	char	*temp;

	str = ft_strnew(BUF);
	ft_printf("FT_SSL> ");
	while (get_next_line(0, &str) > 0)
	{
		i = 0;
		no_error = false;
		temp = str;
		str = ft_strjoin("ft_ssl ", str);
		free(temp);
		argv = ft_strsplit(str, ' ');
		stdin_parse_handler(argc, argv, handler, &no_error);
		no_error == false ? wrong_argument(handler, argv, -1) : 0;
		ft_printf("FT_SSL> ");
		free(str);
		clean_array(argv);
		str = ft_strnew(BUF);
	}
	str ? free(str) : 0;
}
