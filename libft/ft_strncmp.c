/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:38:03 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/21 16:38:05 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	i = (int)0;
	while ((p1[i] != '\0' || p2[i] != '\0') && i < n)
	{
		if (p1[i] > p2[i])
			return (p1[i] - p2[i]);
		if (p1[i] < p2[i])
			return ((p2[i] - p1[i]) * -1);
		i++;
	}
	return (0);
}
