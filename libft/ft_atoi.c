/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:07:21 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/21 11:07:26 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_max(const char *p, signed long long n, int s)
{
	if (n == 922337203685477580 && s == 0 && *p >= '8' && *p <= '9')
		return (-1);
	else if (n > 922337203685477580 && s == 0)
		return (-1);
	else if (n == 922337203685477580 && s == 1 && *p >= '8' && *p <= '9')
		return (0);
	else if (n > 922337203685477580 && s == 1)
		return (0);
	return (2);
}

int			ft_atoi(const char *str)
{
	signed long long	number;
	signed long long	i;
	int					x;

	number = 0;
	i = 0;
	x = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		i = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		if (check_max(str, number, i) != 2)
			return (check_max(str, number, i));
		number *= 10;
		number += (*str - '0');
		str++;
	}
	if (i == 1)
		number = number * -1;
	return (number);
}
