/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:06:29 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/24 15:08:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*l1;
	unsigned char	*l2;

	i = 0;
	l1 = (unsigned char *)s1;
	l2 = (unsigned char *)s2;
	while (i < n)
	{
		if (l1[i] > l2[i])
			return (l1[i] - l2[i]);
		if (l1[i] < l2[i])
			return ((l2[i] - l1[i]) * -1);
		i++;
	}
	return (0);
}
