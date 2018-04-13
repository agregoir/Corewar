/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:44:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/09 20:10:12 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = s1;
	str2 = (char *)s2;
	while (*str1 != '\0')
		str1++;
	while ((*str2 != '\0') && (n != 0))
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
	*str1 = '\0';
	return (s1);
}
