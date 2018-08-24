/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:29:33 by itiievsk          #+#    #+#             */
/*   Updated: 2018/02/13 18:29:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;
	size_t	size;

	size = (int)0;
	i = (int)0;
	length = (int)0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dest[i++] != '\0' && size < dstsize)
		size++;
	i = (int)0;
	while (dest[i++] != '\0')
		length++;
	i = (int)0;
	while (src[i++] != '\0')
		size++;
	i = (int)0;
	while (length < dstsize - 1)
		dest[length++] = src[i++];
	dest[length] = '\0';
	return (size);
}
