/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:55:35 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:43:14 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_3(t_flags *f, char *r, const char *format, int index)
{
	if (f->width > 0 && is_minus_flag(f))
	{
		r = ft_strncat_ze(r, &format[index], 1, f);
		r = ft_strncat_ze(r, no_conv_width(f->width - 1), f->width, f);
	}
	else
	{
		if (f->width > 0)
			r = ft_strncat_ze(r, no_conv_width(f->width - 1), f->width, f);
		r = ft_strncat_ze(r, &format[index], 1, f);
	}
	return (r);
}

int		ft_get_conv(char **result, t_flags *flags, va_list ap, int i[3])
{
	*result = call_fmt(g_tab[i[0]], ap, flags, *result);
	if (flags->curmax == 1)
	{
		*result[i[1]] = '\0';
		return (ft_display(ap, flags, *result, 1));
	}
	i[1] = ft_strlen_zero(*result, flags);
	return (0);
}

void	ft_while(const char *format, int i[3])
{
	while (g_tab[i[0]].flag != format[i[2]] && g_tab[i[0]].flag != 0)
		(i[0])++;
}

int		ft_printf_2(t_flags *f, va_list ap, const char *format, int i[3])
{
	char	*result;
	int		len;

	len = 0;
	result = ft_strnew(200);
	while (format[++i[2]] != '\0')
	{
		if (format[i[2]] != '%')
			i[2] ? ft_strncat_ze(result, &format[i[2]], 1, f)
			: ft_strncat(result, &format[i[2]], 1);
		else
		{
			i[2]++;
			f = parse_flags(format, &i[2], f);
			if (!format[i[2]])
				break ;
			ft_while(format, i);
			if (g_tab[i[0]].flag == format[i[2]])
				len = ft_get_conv(&result, f, ap, i);
			else
				result = ft_printf_3(f, result, format, i[2]);
			i[0] = 0;
		}
	}
	return (len ? len : ft_display(ap, f, result, 0));
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i[3];
	t_flags	*flags;

	va_start(ap, format);
	i[1] = 0;
	flags = NULL;
	i[0] = 0;
	i[2] = -1;
	return (ft_printf_2(flags, ap, format, i));
}
