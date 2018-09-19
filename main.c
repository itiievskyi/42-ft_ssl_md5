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
	ft_strncpy(handler[2].func, "sha224", FUNC_NAME);
	ft_strncpy(handler[2].type, "md", 3);
	handler[2].handler = sha224;
	ft_strncpy(handler[3].func, "sha512", FUNC_NAME);
	ft_strncpy(handler[3].type, "md", 3);
	handler[3].handler = sha512;
	ft_strncpy(handler[4].func, "sha384", FUNC_NAME);
	ft_strncpy(handler[4].type, "md", 3);
	handler[4].handler = sha384;
	ft_strncpy(handler[5].func, "sha512256", FUNC_NAME);
	ft_strncpy(handler[5].type, "md", 3);
	handler[5].handler = sha512256;
	ft_strncpy(handler[6].func, "sha512224", FUNC_NAME);
	ft_strncpy(handler[6].type, "md", 3);
	handler[6].handler = sha512224;
}

int		main(int argc, char **argv)
{
	int					i;
	bool				no_error;
	static t_ssl_func	handler[FUNCTIONS];

	i = 0;
	no_error = false;
	if (argc == 1)
	{
		stdin_cmd(0, 0, handler, no_error);
		return (0);
	}
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
	no_error == false ? wrong_argument(handler, argv, -1, false) : 0;
	system("leaks ft_ssl");
	return (0);
}
