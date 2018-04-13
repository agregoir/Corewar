/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:56:37 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:11:21 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_p(va_list ap, t_flags *flags)
{
	char	*str;

	flags->length[0] = 'l';
	flags->length[1] = 'l';
	str = flag_x(ap, flags);
	if (!(is_diese_flag(flags)) || (str[0] == '0' && str[1] == '\0'))
		str = ft_strjoin_free("0x", str, 2);
	flags->length[0] = '\0';
	flags->length[1] = '\0';
	return (str);
}

char	*string_back(va_list ap, t_flags *flags)
{
	int		s;
	char	*str;

	if (ft_strchr(flags->length, 'l'))
		return (flag_ups(ap, flags));
	s = flags->width;
	str = va_arg(ap, char*);
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*flag_di(va_list ap, t_flags *flags)
{
	char		*str;
	intmax_t	arg;

	arg = get_intmax_t_arg(ap, flags);
	str = ft_itoa_base_intmax_t(arg, "0123456789", 0);
	flags->type = -1;
	if (arg == 0)
		flags->type = 8;
	return (str);
}

char	*flag_upd(va_list ap, t_flags *flags)
{
	char	*str;

	flags->length[0] = 'l';
	str = flag_di(ap, flags);
	return (str);
}

char	*flag_upo(va_list ap, t_flags *flags)
{
	char	*str;

	flags->length[0] = 'l';
	str = flag_o(ap, flags);
	return (str);
}
