/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:26:06 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/23 18:32:03 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	index;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	index = 0;
	len = (unsigned int)ft_strlen((const char *)s);
	if ((ret = ft_strnew(len)))
	{
		while (index < len)
		{
			ret[index] = f(index, s[index]);
			index++;
		}
	}
	return (ret);
}
