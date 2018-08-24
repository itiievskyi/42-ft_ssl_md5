/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:20:27 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 18:20:29 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*line;

	i = 0;
	ch = (unsigned char)c;
	line = (unsigned char *)s;
	while (i < n)
	{
		if (line[i] == ch)
			return ((void *)&line[i]);
		i++;
	}
	return (NULL);
}
