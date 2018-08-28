/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 14:36:05 by itiievsk          #+#    #+#             */
/*   Updated: 2018/08/28 14:36:07 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		flags_init(t_flags *flags)
{
	flags->p = 0;
	if (flags->q != 1)
		flags->q = 0;
	if (flags->r != 1)
		flags->r = 0;
	flags->s = 0;
}

void		file_init(t_file *file, t_flags *flags)
{
	if (flags)
	{
	}
	file->fd = 0;
	file->q = 0;
	file->r = 0;
}
