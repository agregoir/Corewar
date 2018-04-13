/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:55:13 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/12/23 10:24:55 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *org, size_t len, size_t newlen)
{
	void	*res;

	if (!org)
		return (NULL);
	if (len >= newlen)
		return (org);
	if (len == 0)
		return ((void *)ft_memalloc(newlen));
	res = (void *)malloc(newlen);
	res = ft_memcpy(res, org, len);
	free(org);
	org = NULL;
	return (res);
}
