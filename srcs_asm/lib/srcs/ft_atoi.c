/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:12:27 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/11/14 12:23:14 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == ' ' || c == '\r');
}

int		ft_atoi(const char *str)
{
	int		res;
	size_t	i;
	int		p;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	res = 0;
	p = 1;
	if (str[i] == '-' || str[i] == '+')
		p = str[i++] == '-' ? -1 : 1;
	while (ft_isdigit(str[i]))
	{
		res += p > 0 ? (int)(str[i] - '0') : -1 * (int)(str[i] - '0');
		i++;
		if (!ft_isdigit(str[i]))
			return (res);
		res = res * 10;
	}
	return (0);
}
