/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 14:42:18 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:11:18 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*check_errors_plus(t_flags *flags)
{
	int		i;
	int		i2;

	i2 = 1;
	i = 0;
	while (i < 3)
	{
		i2 = 1;
		if (flags->flag[i] == '+')
			while ((i + i2) < 3)
			{
				if (flags->flag[i + i2] == ' ')
					flags->flag[i + i2] = '9';
				i2++;
			}
		if (flags->flag[i] == ' ')
			while ((i + i2) < 3)
			{
				if (flags->flag[i + i2] == '+')
					flags->flag[i] = '9';
				i2++;
			}
		i++;
	}
	return (flags);
}

t_flags		*check_errors_minus(t_flags *flags)
{
	int		i;
	int		i2;

	i2 = 1;
	i = 0;
	while (i < 3)
	{
		i2 = 1;
		if (flags->flag[i] == '0')
			while ((i + i2) < 3)
			{
				if (is_minus_flag(flags))
					flags->flag[i] = '9';
				i2++;
			}
		if (flags->flag[i] == '-')
			while ((i + i2) < 3)
			{
				if (flags->flag[i + i2] == '0')
					flags->flag[i + i2] = '9';
				i2++;
			}
		i++;
	}
	return (flags);
}

t_flags		*check_errors_flags(t_flags *flags)
{
	check_errors_minus(flags);
	check_errors_plus(flags);
	return (flags);
}
