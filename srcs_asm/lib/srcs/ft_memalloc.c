/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 08:49:49 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/23 21:04:22 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = 0;
	if (0 != (size + 1))
		++size;
	if (0 != (mem = malloc(size)))
		ft_memset(mem, 0, size);
	return (mem);
}
