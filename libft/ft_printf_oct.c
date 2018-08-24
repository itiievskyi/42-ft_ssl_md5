/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:54:28 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/06 12:54:34 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_oct_length(uintmax_t num, t_params *par)
{
	if (num == 0 && par->prec != 0)
		par->length = 1;
	else if (num == 0 && par->prec == 0 && !par->hash)
		par->error = -2;
	else
	{
		while (num)
		{
			par->length++;
			num /= 8;
		}
	}
	if (par->prec >= 0)
		par->zero = 0;
}

int			ft_putoct(uintmax_t num, int *ret, t_params *par)
{
	char	ch;
	char	*set;

	set = "01234567";
	if (par->error == -2)
		return (0);
	if (num >= 8)
	{
		ft_putoct(num / 8, ret, par);
		ch = (set[num % 8]);
	}
	else
		ch = (set[num % 8]);
	ft_write(&ch, ret, 1);
	return (0);
}

void		ft_place_oct(t_params *par, int *ret, int *a, uintmax_t num)
{
	if (par->hash && num != 0 && (par->prec <= (int)par->length))
	{
		ft_write("0", ret, 1);
		*a = *a - 1;
	}
	while (par->prec-- > (int)par->length)
		ft_write("0", ret, 1);
	ft_putoct(num, ret, par);
}

static void	ft_oct_pad(t_params *par, int *ret, int *a)
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
			while ((*a)-- > 1)
				ft_check_pad(par, ret);
	}
}

void		ft_printf_oct(t_params *par, va_list arg, int *ret, int a)
{
	uintmax_t	num;

	num = ft_get_uint(par, 0, arg);
	get_oct_length(num, par);
	if (par->prec > (int)par->length)
		a += par->width - par->prec;
	else
		a += par->width - par->length;
	if (par->error != 1 && a > 0)
	{
		if (par->minus)
			ft_place_oct(par, ret, &a, num);
		ft_oct_pad(par, ret, &a);
		if (!(par->minus))
			ft_place_oct(par, ret, &a, num);
	}
	else if (par->error != 1)
		ft_place_oct(par, ret, &a, num);
}
