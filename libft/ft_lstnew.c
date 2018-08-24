/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:51:01 by itiievsk          #+#    #+#             */
/*   Updated: 2018/03/27 15:51:02 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*lst_content;

	lst_content = ft_memalloc(content_size + 1);
	if (!lst_content)
		return (NULL);
	if (content == NULL)
	{
		lst_content = NULL;
		content_size = 0;
	}
	else
		lst_content = ft_memcpy(lst_content, content, content_size);
	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list != (t_list *)NULL)
	{
		list->content_size = content_size;
		list->next = NULL;
		list->content = lst_content;
	}
	return (list);
}
