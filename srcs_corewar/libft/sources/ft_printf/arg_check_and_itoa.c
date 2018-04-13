/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_and_itoa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:54:00 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:09:32 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_base_uintmax_t(uintmax_t nbr, char *base)
{
	char			*str;
	uintmax_t		len_base;
	int				len_str;
	uintmax_t		tmp;

	tmp = nbr;
	len_str = 0;
	len_base = ft_strlen(base);
	while (tmp >= len_base)
	{
		tmp = tmp / len_base;
		len_str++;
	}
	len_str += 1;
	str = (char*)malloc(sizeof(char) * (len_str + 1));
	str[len_str] = '\0';
	while (--len_str >= 0)
	{
		if (nbr < len_base)
			str[len_str] = base[nbr];
		else
			str[len_str] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (str);
}

char			*ft_itoa_base_intmax_t(intmax_t nbr, char *base, int neg)
{
	char			*str;
	int				len_base;
	int				len_str;
	intmax_t		tmp;

	if (-9223372036854775808U == (unsigned long long)nbr)
		return (ft_strjoin_free("", "-9223372036854775808", 0));
	nbr < 0 ? neg = 1 : neg;
	(neg == 1) ? nbr = ABS(nbr) : nbr;
	tmp = nbr;
	len_str = 0;
	len_base = ft_strlen(base);
	while ((tmp >= len_base) && (len_str += 1))
		tmp = tmp / len_base;
	str = (char*)ft_memalloc(sizeof(char) * (len_str + 2));
	str[len_str + 1] = '\0';
	while (--len_str >= -1)
	{
		if (nbr < len_base)
			str[len_str + 1] = base[nbr];
		else
			str[len_str + 1] = base[nbr % len_base];
		nbr = nbr / len_base;
	}
	return (neg ? ft_strjoin_free("-", str, 2) : str);
}

uintmax_t		get_uintmax_t_arg(va_list ap, t_flags *flags)
{
	uintmax_t		ret;

	ret = 0;
	if (ft_strstr(flags->length, "ll"))
		ret = (uintmax_t)va_arg(ap, unsigned long long int);
	else if (ft_strchr(flags->length, 'l'))
		ret = (uintmax_t)va_arg(ap, unsigned long int);
	else if (ft_strchr(flags->length, 'j'))
		ret = (uintmax_t)va_arg(ap, uintmax_t);
	else if (ft_strchr(flags->length, 'z'))
		ret = (uintmax_t)va_arg(ap, size_t);
	else if (ft_strstr(flags->length, "hh"))
		ret = (unsigned char)va_arg(ap, int);
	else if (ft_strchr(flags->length, 'h'))
		ret = (unsigned short)va_arg(ap, int);
	return (ret);
}

intmax_t		get_intmax_t_arg(va_list ap, t_flags *flags)
{
	intmax_t		arg;

	arg = 0;
	if (ft_strstr(flags->length, "ll"))
		arg = va_arg(ap, long long int);
	else if (ft_strchr(flags->length, 'l'))
		arg = va_arg(ap, long int);
	else if (ft_strchr(flags->length, 'j'))
		arg = va_arg(ap, intmax_t);
	else if (ft_strchr(flags->length, 'z'))
		arg = va_arg(ap, ssize_t);
	else if (ft_strstr(flags->length, "hh"))
		arg = (char)va_arg(ap, int);
	else if (ft_strchr(flags->length, 'h'))
		arg = (short)va_arg(ap, int);
	else
		arg = va_arg(ap, int);
	return (arg);
}
