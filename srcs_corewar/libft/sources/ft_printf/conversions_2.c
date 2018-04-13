/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:45:19 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:11:23 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*flag_o(va_list ap, t_flags *flags)
{
	char		*ret;
	uintmax_t	arg;

	flags->type = -4;
	if (flags->length[0] == '\0')
		arg = (uintmax_t)va_arg(ap, unsigned int);
	else
		arg = get_uintmax_t_arg(ap, flags);
	if (arg == 0)
		flags->type = 9;
	ret = ft_itoa_base_uintmax_t(arg, "01234567");
	return (ret);
}

char			*flag_u(va_list ap, t_flags *flags)
{
	char		*ret;
	uintmax_t	arg;

	flags->type = -6;
	if (flags->length[0] == '\0')
		arg = (uintmax_t)va_arg(ap, unsigned int);
	else
		arg = get_uintmax_t_arg(ap, flags);
	if (arg == 0)
		flags->type = 8;
	ret = ft_itoa_base_uintmax_t(arg, "0123456789");
	return (ret);
}

char			*flag_upu(va_list ap, t_flags *flags)
{
	char		*ret;
	uintmax_t	arg;

	flags->type = -6;
	if (ft_strstr(flags->length, "ll"))
		arg = (uintmax_t)va_arg(ap, unsigned long long int);
	else
		arg = (uintmax_t)va_arg(ap, unsigned long int);
	ret = ft_itoa_base_uintmax_t(arg, "0123456789");
	return (ret);
}

char			*flag_x(va_list ap, t_flags *flags)
{
	char		*ret;
	uintmax_t	arg;

	flags->type = -2;
	if (flags->length[0] == '\0')
		arg = (uintmax_t)va_arg(ap, unsigned int);
	else
		arg = get_uintmax_t_arg(ap, flags);
	if (arg == 0)
		flags->type = 7;
	ret = ft_itoa_base_uintmax_t(arg, "0123456789abcdef");
	return (ret);
}

char			*flag_upx(va_list ap, t_flags *flags)
{
	char		*ret;
	uintmax_t	arg;

	flags->type = -3;
	if (flags->length[0] == '\0')
		arg = (uintmax_t)va_arg(ap, unsigned int);
	else
		arg = get_uintmax_t_arg(ap, flags);
	if (arg == 0)
		flags->type = 7;
	ret = ft_itoa_base_uintmax_t(arg, "0123456789ABCDEF");
	return (ret);
}
