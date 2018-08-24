/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:54:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/21 12:54:30 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int i;
	int t;

	t = n;
	i = 1;
	if (n == 0)
		return (2);
	if (n < 0)
		i++;
	while (t != 0)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*num;
	int		t;
	int		i;

	t = n;
	i = 2;
	if (!(char *)malloc(sizeof(char) * size(n)))
		return (NULL);
	num = (char *)malloc(sizeof(char) * size(n));
	if (n == 0)
		return (num = ft_strdup("0"));
	if (n < 0 && n != -2147483648)
	{
		num[0] = '-';
		t = t * -1;
	}
	while (t != 0)
	{
		num[size(n) - i++] = (t % 10) + '0';
		t = t / 10;
	}
	num[size(n) - 1] = '\0';
	if (n == -2147483648)
		num = ft_strdup("-2147483648");
	return (num);
}
