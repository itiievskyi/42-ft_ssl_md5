/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:46:31 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/27 15:46:33 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, void *content, size_t size)
{
	t_list *temp;

	temp = *alst;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = ft_lstnew(content, size);
	}
	else
		*alst = ft_lstnew(content, size);
}
