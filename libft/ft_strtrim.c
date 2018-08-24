/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:09:24 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 13:09:26 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t		len;
	size_t		i;
	char		*t;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (is_space(s[len - i - 1]))
		i++;
	len = len - i;
	if (len == 0)
	{
		t = ft_strdup("");
		return (t);
	}
	i = 0;
	while (is_space(s[i]))
		i++;
	len = len - i;
	t = ft_strsub(s, (unsigned int)i, len);
	if (t == NULL)
		return (NULL);
	return (t);
}
