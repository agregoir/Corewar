/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:12:16 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/07/30 21:25:22 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	count;
	char	p;

	count = *s == c ? 0 : 1;
	p = *s;
	if (*s == 0)
		return (0);
	while (*s)
	{
		s++;
		if (*s && p == c && *s != c)
			count++;
		p = *s;
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	size_t	len;
	size_t	i;
	char	**tab;

	count = ft_count(s, c);
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * count + 1)))
		exit(0);
	i = 0;
	while (count--)
	{
		while (*s && *s == c)
			s++;
		len = ft_wordlen(s, c);
		tab[i] = ft_strsub(s, 0, len);
		s += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
