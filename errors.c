/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 13:47:39 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/27 13:47:41 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	usage(void)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	exit(-1);
}

void	wrong_argument(t_ssl_func handler[], char **argv, int i)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n", argv[1]);
	ft_printf("Standard commands:\n");
	while (++i < FUNCTIONS && ft_strequ(handler[i].type, "sc"))
		ft_printf("%s\n", handler[i].func);
	ft_printf("\nMessage Digest commands:\n");
	i -= 1;
	while (++i < FUNCTIONS && ft_strequ(handler[i].type, "md"))
		ft_printf("%s\n", handler[i].func);
	ft_printf("\nCipher commands:\n");
	i -= 1;
	while (++i < FUNCTIONS && ft_strequ(handler[i].type, "cc"))
		ft_printf("%s\n", handler[i].func);
	ft_printf("\n");
}
