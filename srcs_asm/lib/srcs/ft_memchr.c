/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:18:16 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/24 17:06:14 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ret;
	size_t			i;
	unsigned char	cc;

	cc = (unsigned char)c;
	ret = (unsigned char*)s;
	i = 0;
	while (i++ < n)
	{
		if (*(ret) == cc)
			return ((void *)ret);
		ret++;
	}
	return (NULL);
}
