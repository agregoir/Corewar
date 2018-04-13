/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:44:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/09 20:11:06 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*strnew;
	size_t	i;

	i = 0;
	size++;
	strnew = (char *)malloc(sizeof(char) * size);
	if ((strnew == 0) || (size == 0))
		return (NULL);
	while (i < size)
	{
		strnew[i] = '\0';
		i++;
	}
	return (strnew);
}
