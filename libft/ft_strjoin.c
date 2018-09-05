/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:51:42 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 12:51:43 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		y;
	char	*s;
	int		size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	x = 0;
	y = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((s = (char*)malloc(sizeof(*s) * (size + 1))) == NULL)
		return (NULL);
	while (s1[x] != '\0')
		s[y++] = s1[x++];
	x = 0;
	while (s2[x] != '\0')
		s[y++] = s2[x++];
	s[y] = '\0';
	return (s);
}
