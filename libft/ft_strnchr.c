/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:02:06 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/07 13:02:08 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int size)
{
	int		i;
	char	ch;
	char	*line;

	i = 0;
	ch = (char)c;
	line = (char *)s;
	if (c == '\0')
	{
		while (line[i] != '\0')
			i++;
		return (&line[i]);
	}
	while (line[i] != '\0' && i < size)
	{
		if (line[i] == ch)
			return ((char *)&line[i]);
		i++;
	}
	return (NULL);
}
