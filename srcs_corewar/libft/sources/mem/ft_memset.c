/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:36:36 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/05 04:06:47 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		a;
	char				*bb;

	i = 0;
	a = (unsigned char)c;
	bb = (char *)b;
	while (i != len)
	{
		bb[i] = a;
		i++;
	}
	return (b);
}
