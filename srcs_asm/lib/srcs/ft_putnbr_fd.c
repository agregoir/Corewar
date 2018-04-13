/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:10:28 by fel-mazo          #+#    #+#             */
/*   Updated: 2016/11/13 09:46:23 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digits[10];
	int		index;
	int		s;
	int		p;

	p = n;
	index = 0;
	if (n < 0)
		ft_putchar_fd('-', fd);
	s = p > 0 ? 1 : -1;
	while (p > 9 || p < -9)
	{
		digits[index] = (p % 10) * s + '0';
		index++;
		p = p / 10;
	}
	digits[index] = p * s + '0';
	while (index >= 0)
		ft_putchar_fd(digits[index--], fd);
}
