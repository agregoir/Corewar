/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:58:30 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/23 19:21:43 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	while (*(s + start + i) && i < len)
	{
		ret[i] = s[i + start];
		i++;
	}
	return (ret);
}
