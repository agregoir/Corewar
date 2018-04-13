/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 04:04:02 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/05 02:15:01 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	nb = 0;
	sign = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\r') ||
			(str[i] == '\f') || (str[i] == '\n') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		sign = 1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	if (sign == 1)
		return (-nb);
	else
		return (nb);
}
