/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:11:37 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/12/03 00:26:38 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*herep;
	size_t	this;

	herep = s1 + ft_strlen((const char *)s1);
	this = ft_strlen(s2);
	herep = ft_memcpy((void *)herep, (const void *)s2, this + 1);
	return (s1);
}

char	*strcat_free(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strcat(s1, s2);
	free(s1);
	return (ret);
}
