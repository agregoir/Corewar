/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:42:04 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/12/02 19:17:38 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len;
	unsigned int	i;
	char			*ret;

	if (!s1 || !s2)
		return (NULL);
	len1 = (unsigned int)ft_strlen((const char *)s1);
	len = len1 + (unsigned int)ft_strlen((const char *)s2);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	i = 0;
	if (ret == NULL)
		return (NULL);
	while (i < len1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		ret[i] = s2[i - len1];
		i++;
	}
	return (ret);
}

char	*join_free(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}
