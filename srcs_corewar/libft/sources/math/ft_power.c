/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:38:55 by agregoir          #+#    #+#             */
/*   Updated: 2017/11/30 18:43:20 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_power(int nb, int power)
{
	int		result;

	if (power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	result = 1;
	while (power--)
		result = result * nb;
	return (result);
}
