/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:31:14 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 15:31:16 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	size;
	char			*map;

	i = -1;
	size = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	while (s[++i] != '\0')
		if (f(i, s[i]))
			size++;
	map = ft_strnew(size);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (f(i, s[i]))
			map[k++] = f(i, s[i]);
		i++;
	}
	return (map);
}
