/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:34:15 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/30 10:34:48 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstlen(t_list **alst)
{
	size_t	len;
	t_list	*lst;

	if (!alst)
		return (0);
	if (!(lst = *alst))
		return (0);
	len = 1;
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
