/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_nocase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 17:59:32 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/14 17:59:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_nocase(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*p1;
	unsigned char	*p2;
	unsigned int	char1;
	unsigned int	char2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = 0;
	while (p1[i] != '\0' || p2[i] != '\0')
	{
		char1 = ft_tolower(p1[i]);
		char2 = ft_tolower(p2[i]);
		if (char1 > char2)
			return (char1 - char2);
		if (char1 < char2)
			return ((char2 - char1) * -1);
		i++;
	}
	return (0);
}
