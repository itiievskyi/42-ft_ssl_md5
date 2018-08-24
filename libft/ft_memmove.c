/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:30:07 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/24 15:30:10 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*memdst;
	unsigned char	*memsrc;

	memdst = (unsigned char *)dst;
	memsrc = (unsigned char *)src;
	if (memsrc > memdst)
	{
		while (len > 0)
		{
			*memdst++ = *memsrc++;
			len--;
		}
	}
	else
	{
		memsrc = memsrc + len - 1;
		memdst = memdst + len - 1;
		while (len > 0)
		{
			*memdst-- = *memsrc--;
			len--;
		}
	}
	return (dst);
}
