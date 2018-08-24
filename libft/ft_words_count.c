/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:05:07 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/09 10:05:09 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

int			ft_words_count(char *str)
{
	int		words;
	int		i;
	char	*line;

	words = 0;
	i = 0;
	line = ft_strtrim(str);
	while (line[i] != '\0')
	{
		while (line[i] != '\0' && is_space(line[i]))
			i++;
		if (line[i] != '\0' && !is_space(line[i]))
			words++;
		while (line[i] != '\0' && !is_space(line[i]))
			i++;
		while (line[i] != '\0' && is_space(line[i]))
			i++;
	}
	if (line)
		free(line);
	return (words);
}
