/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:32:25 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/24 17:05:33 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_digits(int nb)
{
	unsigned int	count;

	count = 0;
	if (nb < 10 && nb > -10)
		return (1);
	while (nb)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

char					*ft_itoa(int nb)
{
	unsigned int	i;
	char			*ret;

	i = ft_digits(nb);
	if (!(ret = (char *)ft_strnew(i + (nb < 0))))
		return (NULL);
	if (nb < 0)
		ret[0] = '-';
	while (i--)
	{
		ret[i + (nb < 0)] = '0' + (nb % 10) * (nb > 0 ? 1 : -1);
		nb = nb / 10;
	}
	return (ret);
}
