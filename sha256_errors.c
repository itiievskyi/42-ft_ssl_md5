/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:41:13 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/07 09:41:14 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		sha256_s_error(t_flags *flags)
{
	free(flags);
	ft_printf("ft_ssl: sha256: option requires an argument -- s\n");
	ft_printf("usage: ft_ssl sha256 [-pqrt] [-s string] [files ...]\n");
	exit(-1);
}

void		sha256_err_flag(char ch, t_flags *flags)
{
	free(flags);
	ft_printf("ft_ssl sha256: illegal option -- %c\n", ch);
	ft_printf("usage: ft_ssl sha256 [-pqrt] [-s string] [files ...]\n");
	exit(-1);
}
