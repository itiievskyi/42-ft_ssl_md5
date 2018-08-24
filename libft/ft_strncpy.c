/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:12:18 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/22 12:12:20 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t index;

	index = (int)0;
	while (index < len && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (len > index)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}
