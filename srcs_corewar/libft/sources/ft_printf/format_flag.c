/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:17:51 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:11:30 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*plus_flag(char *str, int *len)
{
	if (str[0] != '-')
	{
		str = ft_strjoin_free("+", str, 2);
		*len += 1;
	}
	return (str);
}

char	*space_flag(char *str, int *len)
{
	if (str[0] != '-')
	{
		str = ft_strjoin_free(" ", str, 2);
		*len += 1;
	}
	return (str);
}

char	*diese_flag(t_flags *flags, char *s2, char *str, int *len)
{
	if (flags->type == -4)
	{
		if (str[0] != '0')
		{
			s2 = ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
			s2[0] = '0';
			str = ft_strjoin_free(s2, str, 3);
			*len += 1;
		}
	}
	else
	{
		s2 = ft_memalloc(sizeof(char) * (ft_strlen(str) + 1));
		s2[0] = '0';
		if (flags->type == -2)
			s2[1] = 'x';
		else if (flags->type == -3)
			s2[1] = 'X';
		str = ft_strjoin_free(s2, str, 3);
		*len += 2;
	}
	return (str);
}

char	*zero_flag_2(t_flags *flags, char *news, char **str)
{
	if ((is_zero_flag(flags) && (flags->type == 0))
		|| (is_zero_flag(flags) && (flags->type != 0)
		&& flags->precision == -1))
	{
		if (!is_diese_flag(flags) && *str[0] == '0' && flags->width < 0)
			return (news);
		if (*str[0] == '-' || *str[0] == '+')
		{
			news[0] = *str[0];
			*str[0] = '0';
		}
		if (news[flags->width] != '-' && news[flags->width] != '+')
		{
			if (flags->width > flags->precision)
				news[flags->width] = '0';
			else
				news[flags->width] = ' ';
		}
		flags->width--;
		if (news[0] == '0' && is_space_flag(flags))
			news[0] = ' ';
	}
	else
		news[flags->width--] = ' ';
	return (news);
}

char	*zero_flag(t_flags *flags, char *news, char **str)
{
	while ((flags->width) >= 0)
	{
		news = zero_flag_2(flags, news, str);
	}
	return (news);
}
