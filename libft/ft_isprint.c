/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 18:23:05 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/21 18:23:07 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (ft_isalpha(c))
		return (ft_isalpha(c));
	else if (ft_isdigit(c))
		return (ft_isdigit(c));
	else if (c == 32)
		return (1);
	else if ((c >= 123 && c <= 126) || (c >= 91 && c <= 96))
		return (1);
	else if ((c >= 58 && c <= 64) || (c >= 33 && c <= 47))
		return (1);
	return (0);
}
