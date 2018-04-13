/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:46:40 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/20 15:25:44 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*sc;

	sc = (char *)s;
	res = 0;
	while (1)
	{
		if (*sc == (char)c)
			res = sc;
		if (*sc == '\0')
			return (res);
		sc++;
	}
}
