/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:54:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/06 12:54:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_int_length(uintmax_t num, t_params *par)
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
			num /= 10;
		}
	}
	if (par->apostrophe && (par->apostrophe = par->length) < 4)
		par->apostrophe = 0;
	if (par->apostrophe)
		par->length += par->apostrophe / 3;
	if (par->convert == 'd' && par->zero == 1 && par->plus)
	{
		par->zero = 0;
		par->prec = par->width - 1;
	}
	if (par->prec >= 0)
		par->zero = 0;
}

int			ft_putnum(uintmax_t num, int *ret, t_params *par)
{
	char	ch;

	if (par->error == -2)
		return (0);
	if (num >= 10)
	{
		ft_putnum(num / 10, ret, par);
		ch = (num % 10 + '0');
	}
	else
		ch = ('0' + num);
	if (par->apostrophe)
	{
		if (par->apostrophe % 3 == 0)
			ft_write(",", ret, 1);
		par->apostrophe -= 1;
	}
	ft_write(&ch, ret, 1);
	return (0);
}

uintmax_t	ft_get_uint(t_params *par, uintmax_t n, va_list arg)
{
	if ((par->mod == 'l' || par->mod == 'z'))
		n = va_arg(arg, unsigned long);
	else if (par->mod == '2')
		n = va_arg(arg, unsigned long long);
	else if (par->mod == 'j')
		n = va_arg(arg, uintmax_t);
	else if (par->mod == 'h')
		n = (unsigned short)va_arg(arg, int);
	else if (par->mod == '1')
		n = (unsigned char)va_arg(arg, int);
	else
		n = va_arg(arg, unsigned int);
	return (n);
}

uintmax_t	ft_get_num(t_params *par, uintmax_t n, intmax_t s, va_list arg)
{
	if (par->convert == 'u')
		n = ft_get_uint(par, 0, arg);
	else if (par->convert == 'd' && (par->mod == 'l' || par->mod == 'z'))
		s = va_arg(arg, long);
	else if (par->convert == 'd' && par->mod == '2')
		s = va_arg(arg, long long);
	else if (par->convert == 'd' && par->mod == 'j')
		s = va_arg(arg, intmax_t);
	else if (par->convert == 'd' && par->mod == 'h')
		s = (short)va_arg(arg, int);
	else if (par->convert == 'd' && par->mod == '1')
		s = (signed char)va_arg(arg, int);
	else if (par->convert == 'd')
		s = va_arg(arg, int);
	if (par->convert == 'd' && s < 0)
	{
		par->plus = '-';
		return (n = (uintmax_t)(s * -1));
	}
	else if (par->convert == 'd')
		return (n = (uintmax_t)s);
	else
		return (n);
}

void		ft_printf_i(t_params *par, va_list arg, int *ret, int a)
{
	uintmax_t	num;

	num = ft_get_num(par, 0, 0, arg);
	get_int_length(num, par);
	if (par->space && !par->plus)
	{
		ft_write(" ", ret, 1);
		a--;
	}
	if (par->prec > (int)par->length)
		a += par->width - par->prec;
	else
		a += par->width - par->length;
	if (par->error != 1 && a > 0)
	{
		if (par->minus)
			ft_place_int(par, ret, &a, num);
		ft_int_pad(par, ret, &a);
		if (!(par->minus))
			ft_place_int(par, ret, &a, num);
	}
	else if (par->error != 1)
		ft_place_int(par, ret, &a, num);
}
