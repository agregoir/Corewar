/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:34:59 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/30 10:35:03 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list **alst)
{
	t_list	*this;

	if (!alst)
		return ;
	this = *alst;
	while (this)
	{
		write(1, this->content, this->content_size);
		this = this->next;
	}
}
