/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 06:13:45 by agregoir          #+#    #+#             */
/*   Updated: 2018/01/29 12:29:14 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;
	char	*ptrsrc;
	char	*ptrdst;

	ptrdst = (char*)dst;
	ptrsrc = (char*)src;
	index = 0;
	if (n == 0)
		return (ptrdst);
	while (index < n)
	{
		ptrdst[index] = ptrsrc[index];
		index++;
	}
	return (ptrdst);
}
