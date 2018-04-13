/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 05:12:34 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/05 03:55:20 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_display(int sign, char *str, int n)
{
	if (sign == 1)
	{
		str[0] = '-';
		str[1] = n + '0';
	}
	if (sign == 0)
		str[0] = n + '0';
	return (str);
}

static int			ft_sign(int *n)
{
	if (*n < 0)
	{
		*n = -*n;
		return (1);
	}
	else
		return (0);
}

char				*ft_itoa(int n)
{
	int		len;
	int		tmp_n;
	char	*str;
	int		sign;

	len = 2;
	sign = ft_sign(&n);
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	tmp_n = n;
	while ((tmp_n >= 10) && (len++))
		tmp_n = tmp_n / 10;
	if (!(str = (char *)malloc(sizeof(char) * (len + sign))))
		return (NULL);
	str[--len + sign] = '\0';
	while (--len != 0)
	{
		str[len + sign] = n % 10 + '0';
		n = n / 10;
	}
	return (ft_display(sign, str, n));
}
