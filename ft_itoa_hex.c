/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:48:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/09/17 11:48:54 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static uint32_t	swap_endian(uint32_t state)
{
	uint32_t	ret;

	ret = ((state >> 24) & 0xff) |
			((state << 8) & 0xff0000) |
			((state >> 8) & 0xff00) |
			((state << 24) & 0xff000000);
	return (ret);
}

char			*ft_itoa_hex(uint32_t state[], int size, int i, char end)
{
	char		*ret;
	int			j;
	uint32_t	r;
	uint32_t	temp;

	ret = ft_strnew(size);
	r = 0x10000000;
	while (i < size)
	{
		temp = (end == 'L' ? swap_endian(state[i / 8]) : state[i / 8]);
		j = 0;
		while (j < 8)
		{
			ret[i] = HEX[temp / (r >> (4 * j))];
			temp = temp % (r >> (4 * j));
			j++;
			i++;
		}
	}
	return (ret);
}
