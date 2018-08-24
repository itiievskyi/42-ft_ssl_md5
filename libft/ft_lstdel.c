/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:50:21 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/27 15:50:23 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*fwd;

	list = *alst;
	while (list)
	{
		fwd = list->next;
		del(list->content, list->content_size);
		free(list);
		list = fwd;
	}
	*alst = NULL;
}
