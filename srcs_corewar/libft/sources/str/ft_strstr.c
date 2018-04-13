/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:44:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/10 16:54:15 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	b = 0;
	c = 0;
	if (little[a] == '\0')
		return (char*)(big);
	while (big[c] != '\0')
	{
		b = c;
		a = 0;
		while (big[b] == little[a])
		{
			a++;
			b++;
			if (little[a] == '\0')
				return (char*)(&big[c]);
		}
		c++;
	}
	return (NULL);
}
