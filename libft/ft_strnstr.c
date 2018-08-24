/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:51:25 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/22 10:51:27 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	k;
	char	*ptr;

	i = 0;
	k = 0;
	ptr = (char *)str;
	if (to_find[k] == '\0')
		return (ptr);
	while (str[i] != '\0' && i < len)
	{
		while (to_find[k] == str[i + k] && to_find[k] != '\0' && i + k < len)
			k++;
		if (str[i + k - 1] == to_find[k - 1] && to_find[k] == '\0')
			return (&ptr[i]);
		i++;
		k = 0;
	}
	return (NULL);
}
