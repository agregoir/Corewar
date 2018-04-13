/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:09:05 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/22 15:10:40 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && --n > 0)
	{
		s1++;
		s2++;
		i++;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
