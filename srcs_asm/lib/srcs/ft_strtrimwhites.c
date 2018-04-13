/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimwhites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:08:53 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/22 16:12:22 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getstart(char const *s, size_t len)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = (unsigned int)len;
	while (i < l && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
				|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'))
		i++;
	return (i);
}

static unsigned int	ft_getend(char const *s, size_t len)
{
	unsigned int	i;

	i = (unsigned int)len - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
				|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'))
		i--;
	return (i);
}

char				*ft_strtrimwhites(char const *s)
{
	size_t			size;
	size_t			len;
	unsigned int	start;
	unsigned int	end;

	if (*s == '\0')
		return ((char *)ft_memalloc(sizeof(char)));
	len = ft_strlen((const char *)s);
	start = ft_getstart(s, len);
	end = ft_getend(s, len);
	size = (size_t)(end - start + 1);
	return (ft_strsub(s, start, size));
}
