/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:54:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/06 12:54:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_double_length(double num, t_params *par)
{
	uintmax_t		flint;

	flint = (uintmax_t)num;
	if (par->prec == -1 || (par->prec == -1 && par->hash))
		par->prec = 6;
	if (flint)
	{
		while (flint)
		{
			par->length++;
			flint /= 10;
		}
	}
	par->length += par->prec + 1;
}

static int	ft_putdouble(long long num, int *ret, t_params *par)
{
	char	ch;

	if (par->error == -2)
		return (0);
	if (num >= 10)
	{
		ft_putdouble(num / 10, ret, par);
		ch = (num % 10 + '0');
	}
	else
		ch = ('0' + num);
	ft_write(&ch, ret, 1);
	return (0);
}

static void	ft_putmantissa(double num, int *ret, t_params *par)
{
	char	ch;

	while (par->prec-- > 0)
	{
		ch = ((unsigned int)(num * 10)) + '0';
		num *= 10 + 0.0000000000001;
		num -= (unsigned int)(num);
		ft_write(&ch, ret, 1);
	}
}

static void	ft_place_double(t_params *par, int *ret, int *a, double num)
{
	ft_put_sign(par, ret, a);
	par->apostrophe = 0;
	ft_putdouble((long long)num, ret, par);
	if (par->prec > 0 || (par->prec == 0 && par->hash))
		ft_write(".", ret, 1);
	if (par->prec)
		ft_putmantissa(num - (intmax_t)num, ret, par);
}

void		ft_printf_double(t_params *par, va_list arg, int *ret, int a)
{
	long double	num;

	if (par->mod == 'L')
		num = va_arg(arg, long double);
	else
		num = (long double)va_arg(arg, double);
	if (num < 0)
	{
		par->plus = '-';
		num *= -1;
	}
	get_double_length(num, par);
	a = par->width - par->length;
	if (par->error != 1 && a > 0)
	{
		if (par->minus)
			ft_place_double(par, ret, &a, num);
		ft_int_pad(par, ret, &a);
		if (!(par->minus))
			ft_place_double(par, ret, &a, num);
	}
	else if (par->error != 1)
		ft_place_double(par, ret, &a, num);
}
