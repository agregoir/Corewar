/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:31:21 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/13 15:45:04 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;

	ret = ft_strnew(ft_strlen(s1));
	if (ret != NULL)
		ft_memcpy((void *)ret, (const void *)s1, ft_strlen(s1));
	return (ret);
}
