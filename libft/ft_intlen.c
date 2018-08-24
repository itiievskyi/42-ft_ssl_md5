/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 13:30:48 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/13 13:30:50 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int nbr)
{
	int		length;

	length = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		length += 1;
		nbr *= -1;
	}
	while (nbr != 0)
	{
		length += 1;
		nbr /= 10;
	}
	return (length);
}
