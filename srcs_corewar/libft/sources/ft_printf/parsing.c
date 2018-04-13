/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:56:38 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:21:21 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*initialize_flags(void)
{
	t_flags	*parse;

	parse = (t_flags *)ft_memalloc(sizeof(t_flags));
	parse->length = ft_strnew(10);
	parse->width = -1;
	parse->type = 0;
	parse->precision = -1;
	parse->cht = 0;
	parse->backslashno = 0;
	parse->curmax = 0;
	return (parse);
}

int			ft_comparison(char c, int action)
{
	if (action == 1)
	{
		if ((c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
			|| (ft_isdigit(c) == 1) || c == '.' || (c == 'h' || c == 'j'
			|| c == 'z' || c == 'l'))
			return (1);
	}
	else if (action == 2)
	{
		if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
			return (1);
	}
	else if (action == 3)
	{
		if (c == 'h' || c == 'j' || c == 'z' || c == 'l')
			return (1);
	}
	else if (action == 4)
	{
		if (c == '0' || c == '-' || c == '.'
		|| c == 'h' || c == 'j' || c == 'z' || c == 'l')
			return (1);
	}
	return (0);
}

void		olala_le_gros_while(const char *str, int *i, t_flags *parse, int j)
{
	while (ft_comparison(str[*i], 1) == 1)
	{
		while (ft_comparison(str[*i], 2) == 1)
			parse->flag[j++] = str[(*i)++];
		check_errors_flags(parse);
		if (ft_isdigit(str[*i]) == 1)
		{
			if (parse->width <= 0)
				parse->width = ft_atoi(&str[*i]);
			while (ft_isdigit(str[*i]) == 1)
				*i += 1;
		}
		if (str[*i] == '.')
		{
			*i += 1;
			ft_isdigit(str[*i]) ? (parse->precision = ft_atoi(&str[*i]))
			: (parse->precision = 0);
			while (ft_isdigit(str[*i]) == 1)
				*i += 1;
		}
		while (ft_comparison(str[*i], 3) == 1)
			ft_strncat(parse->length, &str[(*i)++], 1);
		if (ft_comparison(str[*i], 4) == 1)
			(*i)++;
	}
}

t_flags		*parse_flags(const char *str, int *i, t_flags *flags)
{
	t_flags	*parse;
	int		j;
	int		backslash;

	backslash = -1;
	j = 0;
	if (flags != NULL)
	{
		backslash = flags->backslashno;
		ft_strclr(flags->length);
		free(flags->length);
		parse = initialize_flags();
		parse->backslashno = backslash;
	}
	else
		parse = initialize_flags();
	olala_le_gros_while(str, i, parse, j);
	if (backslash != -1)
	{
		free(flags);
		flags = NULL;
	}
	return (parse);
}
