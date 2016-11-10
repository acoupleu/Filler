/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 18:20:57 by acoupleu          #+#    #+#             */
/*   Updated: 2016/04/01 23:48:42 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*newlist;
	t_list	*link;
	t_list	*tmp;

	tmp = f(lst);
	if (!(newlist = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	link = newlist;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(link->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		link = link->next;
		lst = lst->next;
	}
	return (newlist);
}
