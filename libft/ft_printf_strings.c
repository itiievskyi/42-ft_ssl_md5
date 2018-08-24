/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:38:22 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/26 12:38:25 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	par_check_str(t_params *par)
{
	if (par->prec == -1 && par->zero == 0)
		return (0);
	return (1);
}

void		ft_printf_string(t_params *par, va_list arg, int *ret, int a)
{
	if (!(par->data = ft_strdup(va_arg(arg, char*))))
	{
		if (!par_check_str(par) && ((par->error = 1)))
			ft_write_string("(null)", 0, ret);
		else
			par->data = ft_strdup("\0");
	}
	else if (par->prec >= 0 && (par->prec < (int)ft_strlen(par->data)))
		(par->data)[par->prec] = '\0';
	if (par->error == 0 && (a = par->width - (int)ft_strlen(par->data)) > 0)
	{
		par->minus ? ft_write_string(par->data, 0, ret) : 0;
		while (a--)
		{
			if (par->zero)
				ft_write("0", ret, 1);
			else
				ft_write(" ", ret, 1);
		}
		(!(par->minus)) ? ft_write_string(par->data, 0, ret) : 0;
		free(par->data);
	}
	else if (par->error == 0)
		ft_write_free_string(par, 0, ret);
}
