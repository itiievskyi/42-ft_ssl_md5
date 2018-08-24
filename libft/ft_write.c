/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 10:21:52 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/26 10:22:08 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_write(const char *c, int *ret, int size)
{
	write(1, c, size);
	*ret = *ret + 1;
}

void		ft_write_string(const char *s, int index, int *ret)
{
	while (s[index] != '\0')
		ft_write(&(s[index++]), ret, 1);
}

void		ft_write_free_string(t_params *par, int index, int *ret)
{
	while (par->data[index] != '\0')
		ft_write(&(par->data[index++]), ret, 1);
	free(par->data);
}

void		ft_write_wstring(unsigned char *s, int *ret, int len)
{
	write(1, s, len);
	*ret = *ret + len;
}
