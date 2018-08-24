/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 10:05:34 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/22 10:05:37 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		k;
	char	*ptr;

	if (!str || !to_find)
		return (NULL);
	i = 0;
	k = 0;
	ptr = (char *)str;
	if (to_find[k] == '\0')
		return (ptr);
	while (str[i] != '\0')
	{
		while (to_find[k] == str[i + k] && to_find[k] != '\0')
			k++;
		if (str[i + k - 1] == to_find[k - 1] && to_find[k] == '\0')
			return (&ptr[i]);
		i++;
		k = 0;
	}
	return (NULL);
}
