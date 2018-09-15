/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:15:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/24 11:15:51 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	init_functions(t_ssl_func handler[FUNCTIONS])
{
	ft_strncpy(handler[0].func, "md5", FUNC_NAME);
	ft_strncpy(handler[0].type, "md", 3);
	handler[0].handler = md5;
	ft_strncpy(handler[1].func, "sha256", FUNC_NAME);
	ft_strncpy(handler[1].type, "md", 3);
	handler[1].handler = sha256;
}

void	parse_handler(int argc, char **argv)
{
	int					i;
	bool				no_error;
	static t_ssl_func	handler[FUNCTIONS];

	i = 0;
	no_error = false;
	argc == 1 ? usage() : 0;
	init_functions(handler);
	while (i < FUNCTIONS)
	{
		if (ft_strequ(argv[1], handler[i].func))
		{
			handler[i].handler(argc, argv);
			no_error = true;
		}
		i++;
	}
	no_error == false ? wrong_argument(handler, argv, -1) : 0;
}

int		main(int argc, char **argv)
{
	parse_handler(argc, argv);
//	system("leaks ft_ssl");
	return (0);
}
