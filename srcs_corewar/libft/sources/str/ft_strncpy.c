/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 20:17:34 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/09 20:19:36 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		dst[index] = src[index];
		index++;
	}
	if (len > (ft_strlen(src)))
		while (index < len)
		{
			dst[index] = '\0';
			index++;
		}
	return (dst);
}
