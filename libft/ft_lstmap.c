/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:49:22 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/27 15:49:24 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*curr;
	t_list	*save;

	curr = (t_list *)malloc(sizeof(t_list));
	curr = f(lst);
	save = curr;
	tmp = lst->next;
	while (tmp != NULL)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new = f(tmp);
		tmp = tmp->next;
		curr->next = new;
		curr = curr->next;
		new = NULL;
	}
	return (save);
}
