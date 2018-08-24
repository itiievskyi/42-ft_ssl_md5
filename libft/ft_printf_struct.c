/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:24:40 by itiievsk          #+#    #+#             */
/*   Updated: 2018/04/27 15:24:42 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_params	*ft_get_struct(const char *fmt)
{
	t_params	*par;

	if ((par = (t_params*)malloc(sizeof(t_params))) == NULL)
		return (NULL);
	par->str = fmt;
	par->index = 0;
	par->ret_point = 0;
	par->length = 0;
	par->width = 0;
	par->convert = '\0';
	par->mod = '\0';
	par->prec = -1;
	par->hash = 0;
	par->zero = 0;
	par->space = 0;
	par->minus = 0;
	par->plus = 0;
	par->apostrophe = 0;
	par->error = 0;
	par->p = 0;
	return (par);
}

void		check_err_conv(t_params *par, const char c)
{
	if (!(ft_strchr("diouxXDOUeEfFgGaAcCsSpn%%", c)))
		par->convert = 'c';
}
