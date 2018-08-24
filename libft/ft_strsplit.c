/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:30:19 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/24 16:30:21 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	count_words(char const *s, char c, int p[])
{
	while (s[p[1]] != '\0')
	{
		while (s[p[1]] == c && s[p[1]] != '\0')
			p[1]++;
		if (s[p[1]] != c && s[p[1]] != '\0')
		{
			while (s[p[1]] != c && s[p[1]] != '\0')
				p[1]++;
			p[0]++;
		}
	}
	p[1] = 0;
}

static void	next_word(char const *s, char c, int p[])
{
	p[2] = p[3];
	while (s[p[1]] == c && s[p[1]] != '\0')
		p[1]++;
	p[2] = p[1];
	while (s[p[1]] != c && s[p[1]] != '\0')
		p[1]++;
	p[3] = p[1];
}

static void	write_array(char const *s, char c, int p[], char **arr)
{
	size_t len;

	while (p[4] < p[0])
	{
		next_word(s, c, p);
		len = p[3] - p[2];
		arr[p[4]] = ft_strsub(s, (unsigned int)p[2], len);
		if (arr[p[4]] == NULL)
			p[5] = -1;
		p[4]++;
	}
	arr[p[0]] = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		p[6];

	if (s == NULL)
		return (NULL);
	ft_bzero((char*)p, sizeof(p));
	arr = NULL;
	count_words(s, c, p);
	if (s == NULL)
		return (NULL);
	if (!(arr = (char**)malloc(sizeof(char*) * (p[0] + 1))))
		return (NULL);
	write_array(s, c, p, arr);
	if (p[5] == -1)
		return (NULL);
	return (arr);
}
