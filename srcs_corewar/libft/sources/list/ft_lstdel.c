/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:44:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/10 17:17:11 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*buf;

	tmp = *alst;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			del(tmp->content, tmp->content_size);
			buf = tmp;
			tmp = tmp->next;
			free(buf);
		}
	}
	*alst = NULL;
}
