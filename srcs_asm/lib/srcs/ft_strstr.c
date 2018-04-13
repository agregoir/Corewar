/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:39:22 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/20 16:01:13 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	s;
	size_t	b;
	size_t	len;

	len = ft_strlen(little);
	if (len == 0)
		return ((char *)big);
	s = 0;
	b = 0;
	while (big[s])
	{
		while (big[s + b] && big[s + b] == little[b])
		{
			b++;
			if (b == len)
				return ((char *)(big + s));
		}
		b = 0;
		s++;
	}
	return (0);
}
