/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:29:12 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:12:05 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string_precision(int precision, char *str, int *len)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = ft_memalloc(sizeof(char) * precision + 1);
	while (i < precision)
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	*len = ft_strlen(s2);
	ft_strclr(str);
	free(str);
	str = NULL;
	return (s2);
}

char	*number_precision(t_flags *flags, int *len, char *str, char *s)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		(*len)--;
	s = ft_memalloc(sizeof(char) * flags->precision - (*len) + 1);
	if (str[0] == '-' || str[0] == '+')
	{
		s[0] = str[0];
		str[0] = '0';
		i++;
	}
	while (i < flags->precision - (*len))
	{
		s[i] = '0';
		i++;
	}
	s[i] = '\0';
	str = ft_strjoin_free(s, str, 3);
	*len = ft_strlen(str);
	return (str);
}
