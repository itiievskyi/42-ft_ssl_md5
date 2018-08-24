/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:28:21 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/07 10:28:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_str_swap(char **a, char **b)
{
	char *z;

	z = *a;
	*a = *b;
	*b = z;
}

static void	rev_sort(char **tab)
{
	unsigned int i;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) < 0)
		{
			ft_str_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void		ft_sort_strtab(char **tab, char *type)
{
	unsigned int i;

	i = 0;
	if (ft_strequ(type, "asc"))
	{
		while (tab[i] && tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				ft_str_swap(&tab[i], &tab[i + 1]);
				i = 0;
			}
			else
				i++;
		}
	}
	else if (ft_strequ(type, "desc"))
		rev_sort(tab);
}
