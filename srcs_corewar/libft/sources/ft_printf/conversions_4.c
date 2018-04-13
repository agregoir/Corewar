/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:56:34 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:11:27 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_c(va_list ap, t_flags *flags)
{
	char		*s2;

	if (ft_strchr(flags->length, 'l'))
		return (flag_upc(ap, flags));
	s2 = (char *)ft_memalloc(sizeof(char) * 2);
	s2[0] = (char)va_arg(ap, int);
	s2[1] = '\0';
	if (s2[0] == '\0')
		flags->backslashno += 0;
	return (s2);
}

char	*flag_percent(va_list ap, t_flags *flags)
{
	char *s;

	(void)ap;
	s = (char *)ft_memalloc(sizeof(char) * 2);
	s[0] = '%';
	s[1] = '\0';
	flags->type = 5;
	return (s);
}

char	*no_conv_width(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_memalloc(size + 1);
	str[size] = '\0';
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	return (str);
}
