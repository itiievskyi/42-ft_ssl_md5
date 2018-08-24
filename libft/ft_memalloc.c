/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 10:52:00 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/23 10:52:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area;
	int		i;

	i = (int)size;
	if (i <= 0)
		return (NULL);
	if (!(area = (void*)malloc(sizeof(*area) * i)))
		return (NULL);
	ft_bzero(area, i);
	return (area);
}
