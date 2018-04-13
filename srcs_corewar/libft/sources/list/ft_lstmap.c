/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:44:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/10 17:22:42 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*start;
	t_list	*buf;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp = f(lst);
	lst = lst->next;
	start = tmp;
	while (lst != NULL)
	{
		buf = malloc(sizeof(t_list));
		if (!buf)
			return (NULL);
		buf = f(lst);
		lst = lst->next;
		tmp->next = buf;
		tmp = tmp->next;
		free(buf);
	}
	tmp->next = NULL;
	return (start);
}
