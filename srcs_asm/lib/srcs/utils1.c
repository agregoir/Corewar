/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:00:04 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/17 22:33:09 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	map_c_to_prime(char c)
{
	if (c == '-')
		return (2);
	if (c == '+')
		return (3);
	if (c == ' ')
		return (5);
	if (c == '0')
		return (7);
	if (c == '#')
		return (11);
	return (0);
}

char		*get_flags(char *str, t_job *job)
{
	int		i;

	i = 0;
	while (*str && ft_strchr(FLAGS_STR, *str))
	{
		i = map_c_to_prime(*str);
		if (job->flags % i != 0)
			job->flags *= i;
		++str;
	}
	return (str);
}

char		*get_minw(char *str, t_job *job, va_list args)
{
	int		hold;

	if (*str == '*')
	{
		hold = (int)va_arg(args, int);
		job->flags *= hold < 0 ? 2 : 1;
		job->minw = ABS(hold);
		return (++str);
	}
	while (ft_isdigit(*str))
	{
		job->minw += (t_ui)(*str - '0');
		++str;
		if (!ft_isdigit(*str))
			return (str);
		job->minw *= 10;
	}
	return (str);
}

char		*get_prec(char *str, t_job *job, va_list args)
{
	int		hold;

	if (*str != '.')
		return (str);
	++str;
	if (*str == '*')
	{
		hold = (int)va_arg(args, int);
		job->prec = hold >= 0 ? hold : 0;
		return (++str);
	}
	if (ft_isdigit(*str))
		job->prec = 0;
	while (ft_isdigit(*str))
	{
		job->prec += (*str - '0');
		++str;
		if (!ft_isdigit(*str))
			return (str);
		job->prec *= 10;
	}
	job->prec = 0;
	return (str);
}

char		*get_len(char *str, t_job *job)
{
	int		count;

	count = 0;
	while (*str && ft_strchr(LEN_STR, *str))
	{
		count++;
		if (count == 1)
			job->len = *str;
		if (count == 2)
			job->len = *str + 1;
		++str;
	}
	return (str);
}
