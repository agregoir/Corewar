/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:30:01 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/13 18:02:55 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*herep;
	size_t	size;

	size = ft_strlen(s2);
	herep = s1 + ft_strlen((const char *)s1);
	herep = ft_strncpy(herep, s2, size < n ? size : n);
	*(herep + (size < n ? size : n)) = '\0';
	return (s1);
}
