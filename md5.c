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
#include "md5.h"

void		md5_encrypt(char *str, t_flags *flags)
{
	size_t			len;
	size_t			str_len;
	size_t			i;
	int				j;
	unsigned char	*input;

	if (!str || !flags)
		return ;
	i = -1;
	j = -1;
	str_len = ft_strlen(str);
	len = 512 - (str_len * 8) % 448 + str_len * 8;
	input = (unsigned char*)malloc(sizeof(unsigned char) * len / 8 + 1);
	while (++i < str_len)
		input[i] = str[i];
	input[i] = 128;
	while (++i < len / 8 - 8)
		input[i] = 0;
	while (++i - 1 < len / 8 && (++j > -1))
		input[len / 8 - j - 1] = (str_len * 8 >> (j * 8)) % 256;

	/* CHECKING */

	ft_printf("%s\n", str);
	int y;
	size_t z = -1;
	while (++z < len / 8) {
		for (y = 0; y < 8; y++) {
			ft_printf("%d", !!((input[z] << y) & 0x80));
		}
		ft_printf(" ");
	}
	ft_printf("\nstr_len = %d bytes, length = %d bits, or %d bytes\n", str_len, len, len / 8);

}
