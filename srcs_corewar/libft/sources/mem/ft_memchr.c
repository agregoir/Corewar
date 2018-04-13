/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:17:37 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/05 03:59:55 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	ucc;

	ucc = (unsigned char)c;
	cs = (unsigned char *)s;
	while (n != 0)
	{
		if (*cs == ucc)
			return (cs);
		cs++;
		n--;
	}
	return (NULL);
}
