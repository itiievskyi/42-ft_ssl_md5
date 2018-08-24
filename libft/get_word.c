/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:02:41 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/16 10:02:44 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char			*get_word(char *str, int n)
{
	int		i;
	int		a;
	int		index;
	char	*word;

	i = 0;
	index = 0;
	a = 0;
	while (str[index] != '\0')
	{
		while (is_space(str[index]) && str[index] != '\0')
			index++;
		if (str[index] != '\0')
			i++;
		if (i == n)
			break ;
		while (!(is_space(str[index])) && str[index] != '\0')
			index++;
	}
	while (str[index + a] != '\0' && !(is_space(str[index + a])))
		a++;
	word = ft_strsub(str, index, a);
	return (word);
}
