/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:56:19 by jperez-p          #+#    #+#             */
/*   Updated: 2022/05/09 13:56:20 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*pos_new;
	t_list	*pos_old;

	new_lst = ft_lstnew((*f)(lst->content));
	if (!lst || !(new_lst))
	{
		return (NULL);
	}
	pos_new = new_lst;
	pos_old = lst->next;
	while (pos_old)
	{
		pos_new->next = ft_lstnew((*f)(pos_old->content));
		if (!(pos_new))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		pos_new = pos_new->next;
		pos_old = pos_old->next;
	}
	return (new_lst);
}
