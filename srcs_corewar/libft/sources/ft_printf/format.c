/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:29:37 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:41:59 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width_and_prec2(t_flags *flags, char *str, int *len, char *s2)
{
	if ((flags->type == -1 || flags->type == 8) && is_plus_flag(flags))
		str = plus_flag(str, len);
	if (flags->type == -1 && is_space_flag(flags))
		str = space_flag(str, len);
	if (flags->type <= -2 && is_diese_flag(flags))
		str = diese_flag(flags, s2, str, len);
	if (flags->width != -1 && *len < flags->width)
		str = ft_width(flags, str, len);
	return (str);
}

char	*ft_width_and_precision(t_flags *flags, char *str, int *len)
{
	char	*s2;
	int		i;

	s2 = NULL;
	i = 0;
	*len = ft_strlen_zero(str, flags);
	if (flags->type == 0 && flags->precision != -1 && *len > flags->precision)
		str = string_precision(flags->precision, str, len);
	else if ((flags->type == -1 || flags->type == 8 || flags->type == -4
		|| flags->type == -6 || flags->type == -2 || flags->type == -3
		|| flags->type == 9 || flags->type == 7)
		&& *len <= flags->precision)
		str = number_precision(flags, len, str, s2);
	else if (!flags->precision && (flags->type == 7 || flags->type == 8
		|| flags->type == 9))
	{
		if (flags->width > 0)
			str[0] = ' ';
		else if (flags->type != 9 || (flags->type == 9
			&& !is_diese_flag(flags)))
			str[0] = '\0';
	}
	str = ft_width_and_prec2(flags, str, len, s2);
	return (str);
}

char	*ft_width_2(char *news, t_flags *flags, char *str)
{
	news = ft_memalloc(sizeof(char) * ((flags->width)));
	news[flags->width - 1] = '\0';
	flags->width -= 2;
	while (flags->width >= 0)
	{
		if (is_zero_flag(flags))
			news[flags->width] = '0';
		else
			news[flags->width] = ' ';
		flags->width -= 1;
	}
	ft_strclr(str);
	free(str);
	flags->cht = 1;
	return (news);
}

char	*ft_width(t_flags *flags, char *str, int *len)
{
	char	*news;

	news = NULL;
	if (str[0] == '\0' && flags->cht != 0)
	{
		return (ft_width_2(news, flags, str));
	}
	news = ft_memalloc(sizeof(char) * ((flags->width - (*len) + 1)));
	news[flags->width - (*len)] = '\0';
	flags->width -= ((*len) + 1);
	news = zero_flag(flags, news, &str);
	if (is_diese_flag(flags) && is_zero_flag(flags) && flags->precision == -1)
	{
		if (flags->type >= -2 || flags->type == -3)
			str[1] = '0';
		if (flags->type >= -2)
			news[1] = 'x';
		else if (flags->type == -3)
			news[1] = 'X';
	}
	if (is_minus_flag(flags) || (is_zero_flag(flags) && flags->type == 7))
		return (ft_strjoin_free(str, news, 3));
	return (ft_strjoin_free(news, str, 3));
}
