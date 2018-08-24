/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:23:17 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/02 11:23:19 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printf_char(t_params *par, va_list arg, int *ret)
{
	int		a;
	char	ch;

	if (par->convert == 'c')
		ch = (va_arg(arg, int));
	else if (par->convert == '%')
		ch = '%';
	if (par->prec == 0)
		ch = '\0';
	if ((a = par->width - 1) > 0)
	{
		if (par->minus)
			ft_write(&ch, ret, 1);
		while (a--)
		{
			if (par->zero)
				ft_write("0", ret, 1);
			else
				ft_write(" ", ret, 1);
		}
		if (!(par->minus))
			ft_write(&ch, ret, 1);
	}
	else
		ft_write(&ch, ret, 1);
}

void		ft_printf_c_err(t_params *par, int *ret)
{
	int		a;
	char	ch;

	if (par->convert == 'c')
		ch = par->str[par->ret_point - 1];
	if (par->prec == 0)
		ch = '\0';
	if ((a = par->width - 1) > 0)
	{
		if (par->minus)
			ft_write(&ch, ret, 1);
		while (a--)
		{
			if (par->zero)
				ft_write("0", ret, 1);
			else
				ft_write(" ", ret, 1);
		}
		if (!(par->minus))
			ft_write(&ch, ret, 1);
	}
	else
		ft_write(&ch, ret, 1);
}
