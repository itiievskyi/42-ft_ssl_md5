/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:43:48 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/03 17:43:50 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_check_pad(t_params *par, int *ret)
{
	if (par->zero)
		ft_write("0", ret, 1);
	else
		ft_write(" ", ret, 1);
}

void		ft_int_pad(t_params *par, int *ret, int *a)
{
	if (par->minus)
	{
		if (!par->plus)
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
		else
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
	}
	else
	{
		if (!par->plus)
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
		else
			while ((*a)-- > 1)
				ft_check_pad(par, ret);
	}
}

void		ft_put_sign(t_params *par, int *ret, int *a)
{
	if (par->plus)
	{
		ft_write(&par->plus, ret, 1);
		*a = *a - 1;
	}
}

void		ft_place_int(t_params *par, int *ret, int *a, uintmax_t num)
{
	ft_put_sign(par, ret, a);
	while (par->prec-- > (int)par->length)
		ft_write("0", ret, 1);
	ft_putnum(num, ret, par);
}

void		ft_wchar_err(int *len, int num, t_params *par, int *index)
{
	if (par->prec > -1 && (*len + num) > par->prec)
		*index = -1;
	else
		*len += num;
}
