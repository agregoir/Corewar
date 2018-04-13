/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 08:47:19 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/12/02 11:59:18 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getstart(char const *s, size_t len)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = (unsigned int)len;
	while (i < l && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	return (i);
}

static unsigned int	ft_getend(char const *s, size_t len)
{
	unsigned int	i;

	i = (unsigned int)len - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	return (i);
}

char				*ft_strtrim(char const *s)
{
	size_t			size;
	size_t			len;
	unsigned int	start;
	unsigned int	end;

	if (!s)
		return (NULL);
	len = ft_strlen((const char *)s);
	if (!len)
		return (ft_strnew(0));
	start = ft_getstart(s, len);
	end = ft_getend(s, len);
	if (end == 0 && start != 0)
		return (ft_strnew(0));
	size = (size_t)(end - start + 1);
	return (ft_strsub(s, start, size));
}
