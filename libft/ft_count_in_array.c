/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_in_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 10:56:11 by itiievsk          #+#    #+#             */
/*   Updated: 2018/07/09 10:56:13 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_in_array(char **arr, char *str)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (!arr || !str)
		return (0);
	while (arr[i])
	{
		if (!ft_strcmp(arr[i], str))
			res++;
		i++;
	}
	return (res);
}
