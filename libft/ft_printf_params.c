/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:00:22 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/26 17:00:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_get_flags(t_params *par, size_t i, size_t len)
{
	while ((par->str)[len] != '\0' &&
		ft_strchr("0123456789# -+\'hlLjtzq.*", (par->str)[len]))
		len++;
	if ((par->str)[len])
		par->convert = (par->str)[len];
	check_err_conv(par, (par->str)[len]);
	if (par->convert == '\0')
		par->error = 1;
	if (ft_strnchr(par->str, '+', len))
		par->plus = '+';
	if (ft_strnchr(par->str, '-', len))
		par->minus = 1;
	if (ft_strnchr(par->str, '#', len))
		par->hash = 1;
	if (ft_strnchr(par->str, ' ', len))
		par->space = 1;
	if (ft_strnchr(par->str, '\'', len))
		par->apostrophe = 1;
	while (par->error == 0 && (i < len && ft_strchr("#0 -+\'", (par->str)[i])))
		if ((par->str)[i++] == '0')
			par->zero = 1;
	par->index = i;
	par->ret_point = par->ret_point + len + 1 - ((int)par->error) / 1;
	if (!(ft_strchr("diouxXDOUeEfFgGaAcCsSpn%%", (par->str)[len])))
		par->error = 3;
}

static void		ft_get_width(t_params *par, va_list arg, int i)
{
	i = par->index;
	while (ft_strchr("1234567890*", par->str[par->index]))
	{
		if (par->str[par->index] >= '0' && par->str[par->index] <= '9')
		{
			while (par->str[par->index] >= '0' && par->str[par->index] <= '9')
				par->index += 1;
			par->width = ft_atoi(&par->str[i]);
		}
		if (par->str[par->index] == '*')
		{
			par->width = va_arg(arg, int);
			par->index += 1;
			i = par->index;
		}
	}
	if (par->width < 0)
	{
		par->width *= -1;
		par->minus = 1;
	}
}

static void		ft_get_prec(t_params *par, va_list arg, int i)
{
	i = par->index;
	if (par->str[par->index] == '.')
	{
		par->index += 1;
		par->prec = 0;
		if (par->str[par->index] >= '0' && par->str[par->index] <= '9')
		{
			while (par->str[par->index] >= '0' && par->str[par->index] <= '9')
				par->index += 1;
			par->prec = ft_atoi(&par->str[i + 1]);
		}
		else if (par->str[par->index] == '*')
		{
			par->prec = va_arg(arg, int);
			par->index += i;
		}
	}
	else
		par->index += 1;
	if (par->convert == 'c' || par->convert == '%' || par->prec < 0)
		par->prec = -1;
	if (par->convert == 'd' && par->prec < 0 && par->zero == 0)
		par->prec = 0;
}

static void		ft_handle_conflicts(t_params *par)
{
	if (par->convert == 'p')
	{
		par->convert = 'x';
		par->p = 1;
		par->hash = 1;
		par->mod = 'l';
	}
	if ((par->zero && par->minus))
		par->zero = 0;
	if (par->convert == 'D' || par->convert == 'U' || par->convert == 'O')
	{
		par->mod = 'l';
		par->convert += 32;
	}
	if ((par->plus || ft_strchr("xXuo", par->convert) || par->hash))
		par->space = 0;
	if ((par->convert == 'c' || par->convert == 's') && par->mod == 'l')
		par->convert -= 32;
	if (par->convert == 'u')
		par->plus = 0;
	if (par->zero && par->hash && par->prec < 0
		&& !ft_strchr("fFo", par->convert))
		par->prec = (int)par->width - 2;
	if (ft_strchr("Xx", par->convert) && par->hash)
		par->zero = 0;
}

void			ft_get_param(t_params *par, va_list arg)
{
	ft_get_flags(par, 0, 0);
	ft_get_width(par, arg, 0);
	if (!ft_strchr("hlLjtzqdiouxXDOUeEfFgGaAcCsSpn%%", par->str[par->index]))
		ft_get_prec(par, arg, 0);
	if (ft_strchr("hlLjtzq", par->str[par->index]))
	{
		if (par->str[par->index] == 'h' && par->str[par->index + 1] == 'h')
		{
			par->mod = '1';
			if (par->str[par->index + 2] == 'l')
				par->mod = 'l';
			par->index += 2;
		}
		else if (par->str[par->index] == 'l' && par->str[par->index + 1] == 'l')
		{
			par->mod = '2';
			par->index += 2;
		}
		else
		{
			par->mod = par->str[par->index];
			par->index += 1;
		}
	}
	ft_handle_conflicts(par);
}
