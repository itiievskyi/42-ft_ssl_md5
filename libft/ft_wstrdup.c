/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:13:45 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/22 11:13:49 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t *src)
{
	wchar_t	*dup;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	if (!(dup = (wchar_t*)malloc(sizeof(*dup) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
