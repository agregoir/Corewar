/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:44:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/07 17:27:33 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	to_find;

	to_find = (char)c;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == to_find)
			return (str);
		str++;
	}
	if (*str == to_find)
		return (str);
	return (NULL);
}
