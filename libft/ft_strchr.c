/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:36:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/22 18:36:38 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
	while (line[i] != '\0')
	{
		if (line[i] == ch)
			return ((char *)&line[i]);
		i++;
	}
	return (NULL);
}
