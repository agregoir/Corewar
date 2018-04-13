/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:44:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/09 20:11:22 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		a;
	size_t		b;
	size_t		c;

	a = 0;
	b = 0;
	c = 0;
	if (little[a] == '\0')
		return (char *)(big);
	while ((big[c] != '\0') && len)
	{
		b = c;
		a = 0;
		while ((big[b] == little[a]) && len)
		{
			a++;
			b++;
			len--;
			if (little[a] == '\0')
				return (char *)(&big[c]);
		}
		c++;
		len--;
	}
	return (NULL);
}
