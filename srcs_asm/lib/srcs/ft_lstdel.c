/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 22:50:56 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/24 17:03:38 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*todel;
	t_list	*n;

	if (!alst)
		return ;
	if (!(todel = *alst))
		return ;
	while (1)
	{
		del(todel->content, todel->content_size);
		n = todel->next;
		free(todel);
		if (!n)
			break ;
		todel = n;
	}
	*alst = NULL;
}
