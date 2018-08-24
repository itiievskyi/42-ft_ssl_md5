/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:53:11 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 14:53:13 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	k;
	size_t	size;
	char	*map;

	if (s == NULL)
		return (NULL);
	i = 0;
	size = 0;
	k = 0;
	while (s[i] != '\0')
		if (f(s[i++]))
			size++;
	map = ft_strnew(size);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (f(s[i]))
			map[k++] = f(s[i]);
		i++;
	}
	return (map);
}
