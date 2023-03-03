/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomirand <jomirand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:41:40 by jomirand          #+#    #+#             */
/*   Updated: 2022/11/16 17:16:15 by jomirand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_lst;
	t_list		*list_new;
	t_list		*list_old;

	new_lst = ft_lstnew((*f)(lst->content));
	if (!lst || !f || !del || !new_lst)
		return (NULL);
	list_new = new_lst;
	list_old = lst->next;
	while (list_old)
	{
		list_new->next = ft_lstnew((*f)(list_old->content));
		if (!list_new->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		list_new = list_new->next;
		list_old = list_old->next;
	}
	return (new_lst);
}
