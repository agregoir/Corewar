/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:16:18 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/22 16:42:55 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	s;
	size_t	b;
	size_t	l;

	l = ft_strlen(little);
	if (len == 0)
		return (NULL);
	if (l == 0)
		return ((char *)big);
	s = 0;
	b = 0;
	while (big[s] && s < len)
	{
		while (big[s + b] && big[s + b] == little[b] && s + b < len)
		{
			b++;
			if (b == l)
				return ((char *)(big + s));
		}
		b = 0;
		s++;
	}
	return (NULL);
}
