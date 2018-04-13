/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 09:55:52 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/12/22 04:08:35 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp;

	tmp = ft_memalloc(len);
	if (tmp == NULL)
		return (dst);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, (const void *)tmp, len);
	free(tmp);
	return (dst);
}
