/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:36:47 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/22 18:36:48 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*line;

	i = 0;
	ch = (char)c;
	line = (char *)s;
	while (line[i] != '\0')
		i++;
	if (c == '\0')
		return (&line[i]);
	i--;
	while (i >= 0)
	{
		if (line[i] == ch)
			return ((char *)&line[i]);
		i--;
	}
	return (NULL);
}
