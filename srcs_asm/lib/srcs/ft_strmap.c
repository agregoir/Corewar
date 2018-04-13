/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:54:16 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/23 18:29:57 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*ret;
	unsigned int	index;
	unsigned int	len;

	if (s == NULL)
		return (NULL);
	index = 0;
	len = (unsigned int)ft_strlen((const char *)s);
	ret = ft_strnew(len);
	if (ret)
	{
		while (index < len)
		{
			ret[index] = f(s[index]);
			index++;
		}
	}
	return (ret);
}
