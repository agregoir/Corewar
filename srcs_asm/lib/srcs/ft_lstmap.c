/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:58:15 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/24 17:07:10 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;

	if (!lst)
		return (NULL);
	first = f(lst);
	lst = lst->next;
	new = first;
	while (lst)
	{
		if (!(new->next = f(lst)))
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (first);
}
