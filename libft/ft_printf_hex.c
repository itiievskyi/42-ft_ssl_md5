/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:54:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/06 12:54:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_hex_length(uintmax_t num, t_params *par)
{
	if (num == 0 && par->prec != 0)
		par->length = 1;
	else if (num == 0 && par->prec == 0)
		par->error = -2;
	else
	{
		while (num)
		{
			par->length++;
			num /= 16;
		}
	}
	if (par->prec >= 0)
		par->zero = 0;
}

int			ft_puthex(uintmax_t num, int *ret, t_params *par)
{
	char	ch;
	char	*set;

	set = "0123456789abcdef";
	if (par->error == -2)
		return (0);
	if (num >= 16)
	{
		ft_puthex(num / 16, ret, par);
		if (num % 16 > 9)
			ch = (set[num % 16] - ('x' - (int)par->convert));
		else
			ch = (set[num % 16]);
	}
	else if (num % 16 > 9)
		ch = (set[num] - ('x' - (int)par->convert));
	else
		ch = (set[num]);
	ft_write(&ch, ret, 1);
	return (0);
}

void		ft_place_hex(t_params *par, int *ret, int *a, uintmax_t num)
{
	char ch;

	if (par->hash && num != 0)
	{
		ft_write("0", ret, 1);
		ch = ('x' - ('x' - (int)par->convert));
		ft_write(&ch, ret, 1);
		*a = *a - 2;
	}
	if (par->p && num == 0)
	{
		ft_write("0", ret, 1);
		ft_write("x", ret, 1);
		while (par->prec-- > (int)par->length)
			ft_write("0", ret, 1);
	}
	else
		while (par->prec-- > (int)par->length)
			ft_write("0", ret, 1);
	ft_puthex(num, ret, par);
}

static void	ft_hex_pad(t_params *par, int *ret, int *a)
{
	if (par->minus)
	{
		if (!par->hash)
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
		else
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
	}
	else
	{
		if (!par->hash)
			while ((*a)-- > 0)
				ft_check_pad(par, ret);
		else
			while ((*a)-- > 2)
				ft_check_pad(par, ret);
	}
}

void		ft_printf_hex(t_params *par, va_list arg, int *ret, int a)
{
	uintmax_t	num;

	num = ft_get_uint(par, 0, arg);
	get_hex_length(num, par);
	if (par->prec > (int)par->length)
		a += par->width - par->prec;
	else
		a += par->width - par->length;
	if (par->p && num == 0 && par->minus)
		a = a - 2;
	if (par->error != 1 && a > 0)
	{
		if (par->minus)
			ft_place_hex(par, ret, &a, num);
		ft_hex_pad(par, ret, &a);
		if (!(par->minus))
			ft_place_hex(par, ret, &a, num);
	}
	else if (par->error != 1)
		ft_place_hex(par, ret, &a, num);
}
