/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:51:42 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 12:51:43 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char	*ft_strjoin_size(char const *s1, char const *s2, size_t size)
{
	size_t	x;
	size_t	y;
	size_t	len_s1;
	size_t	len_s2;
	char	*s;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	x = 0;
	y = 0;
	if ((s = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	len_s1 = (size % BUF == 0 ? (size - BUF) : ( size - (size % BUF)));
	len_s2 = size - len_s1;
	while (x < len_s1)
		s[y++] = s1[x++];
	x = 0;
	while (x < len_s2)
		s[y++] = s2[x++];
	s[size] = '\0';
	return (s);
}
