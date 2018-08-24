/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:10:50 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 17:10:51 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*memdst;
	unsigned char	*memsrc;

	memdst = (unsigned char *)dst;
	memsrc = (unsigned char *)src;
	while (n > 0)
	{
		*memdst = *memsrc;
		memdst++;
		memsrc++;
		n--;
	}
	return (dst);
}
