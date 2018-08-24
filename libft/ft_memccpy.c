/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:36:25 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 17:36:27 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	ch;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
		if (s2[i - 1] == ch)
			return (&s1[i]);
	}
	return (NULL);
}
