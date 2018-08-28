/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 16:55:23 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/28 16:55:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		md5_s_error(t_flags *flags)
{
	free(flags);
	ft_printf("ft_ssl: md5: option requires an argument -- s\n");
	ft_printf("usage: ft_ssl md5 [-pqrt] [-s string] [files ...]\n");
	exit(-1);
}

void		md5_err_flag(char ch, t_flags *flags)
{
	free(flags);
	ft_printf("ft_ssl md5: illegal option -- %c\n", ch);
	ft_printf("usage: ft_ssl md5 [-pqrt] [-s string] [files ...]\n");
	exit(-1);
}
