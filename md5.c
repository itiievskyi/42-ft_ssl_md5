/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 17:16:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/24 17:16:33 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		md5_encrypt(char *str, t_flags *flags)
{
	size_t			len;
	unsigned char	*input;

	if (!str || !flags)
		return ;
	len = 512 - (ft_strlen(str) * 8) / 448 + ft_strlen(str) * 8;
	input = (unsigned char*)malloc(sizeof(unsigned char) * len / 8 + 1);
	input[len / 8] = '\0';
	ft_printf("%s\n", str);
//	(!flags->s) ? free(str) : 0;
}
