/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 10:57:36 by itiievsk          #+#    #+#             */
/*   Updated: 2018/05/03 10:57:37 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		get_wchar(unsigned char wch[], int *len, int num)
{
	if (num >= 0 && num <= 127)
		wch[0] = num;
	else if (num >= 128 && num <= 2047)
	{
		wch[0] = (192 + (num / 64));
		wch[1] = (128 + num % 64 % 64);
		*len = 2;
	}
	else if (num >= 2048 && num <= 65535)
	{
		wch[0] = (224 + (num / 4096));
		wch[1] = (128 + (num % 4096) / 64);
		wch[2] = (128 + (num % 4096) % 64);
		*len = 3;
	}
	else if (num >= 65536 && num <= 1114111)
	{
		wch[0] = (240 + (num / 524288));
		wch[1] = (128 + (num % 524288) / 4096);
		wch[2] = (128 + (num % 524288) % 4096 / 64);
		wch[3] = (128 + (num % 524288) % 4096 % 64);
		*len = 4;
	}
}

void			ft_printf_wchar(t_params *par, va_list arg, int *ret)
{
	int				a;
	int				len;
	unsigned char	wch[4];

	len = 1;
	ft_bzero(wch, 4);
	get_wchar(wch, &len, (va_arg(arg, int)));
	if (par->prec >= 0 && (par->prec < len))
		par->prec = len;
	if (par->error == 0 && (a = par->width - len) > 0)
	{
		if (par->minus)
			ft_write_wstring(wch, ret, len);
		while (a--)
		{
			if (par->zero)
				ft_write("0", ret, 1);
			else
				ft_write(" ", ret, 1);
		}
		if (!(par->minus))
			ft_write_wstring(wch, ret, len);
	}
	else if (par->error == 0)
		ft_write_wstring(wch, ret, len);
}

static int		record_wstr(int num, unsigned char *wstr)
{
	if (num >= 0 && num <= 127)
		wstr[0] = num;
	else if (num >= 128 && num <= 2047)
	{
		wstr[0] = (192 + (num / 64));
		wstr[1] = (128 + num % 64 % 64);
		return (2);
	}
	else if (num >= 2048 && num <= 65535)
	{
		wstr[0] = (224 + (num / 4096));
		wstr[1] = (128 + (num % 4096) / 64);
		wstr[2] = (128 + (num % 4096) % 64);
		return (3);
	}
	else if (num >= 65536 && num <= 1114111)
	{
		wstr[0] = (240 + (num / 524288));
		wstr[1] = (128 + (num % 524288) / 4096);
		wstr[2] = (128 + (num % 524288) % 4096 / 64);
		wstr[3] = (128 + (num % 524288) % 4096 % 64);
		return (4);
	}
	return (1);
}

unsigned char	*get_wlength(int *len, int index, t_params *par, va_list arg)
{
	unsigned char	*wstr;
	wchar_t			*str;
	int				num;

	if (!(str = ft_wstrdup(va_arg(arg, wchar_t*))))
		return (NULL);
	while (str[index] && index > -1 && (num = (int)str[index++]))
	{
		if (num >= 0 && num <= 127)
			ft_wchar_err(len, 1, par, &index);
		else if (num >= 128 && num <= 2047)
			ft_wchar_err(len, 2, par, &index);
		else if (num >= 2048 && num <= 65535)
			ft_wchar_err(len, 3, par, &index);
		else if (num >= 65536 && num <= 1114111)
			ft_wchar_err(len, 4, par, &index);
	}
	if (!(wstr = (unsigned char*)malloc(sizeof(unsigned char) * (int)(*len))))
		return (NULL);
	index = 0;
	num = 0;
	while (num < (int)(*len))
		num += record_wstr((int)str[index++], &wstr[num]);
	free(str);
	return (wstr);
}

void			ft_printf_wstr(t_params *par, va_list arg, int *ret, int len)
{
	int				a;
	unsigned char	*wstr;

	wstr = NULL;
	if (!(wstr = get_wlength(&len, 0, par, arg)))
	{
		ft_write_wstring((unsigned char *)"(null)", ret, 6);
		par->error = 1;
	}
	if (par->prec >= 0 && (par->prec < len))
		len = par->prec;
	if (!par->error && ((a = par->width - len) > 0))
	{
		if (par->minus)
			ft_write_wstring(wstr, ret, len);
		while (a--)
			ft_check_pad(par, ret);
		if (!(par->minus))
			ft_write_wstring(wstr, ret, len);
	}
	else if (par->error == 0)
		ft_write_wstring(wstr, ret, len);
	free(wstr);
}
