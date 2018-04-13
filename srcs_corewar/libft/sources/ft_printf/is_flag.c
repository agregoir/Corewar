/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:54:00 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:11:38 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_space_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		is_minus_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		is_plus_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int		is_diese_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int		is_zero_flag(t_flags *flags)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (flags->flag[i] == '0')
			return (1);
		i++;
	}
	return (0);
}
