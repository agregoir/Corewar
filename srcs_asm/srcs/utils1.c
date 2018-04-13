/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:48:50 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/12/26 17:58:16 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		is_label_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_')
		return (1);
	return (0);
}

char		is_param_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_'
		|| c == L_C || c == '-' || c == D_C || c == '+')
		return (1);
	return (0);
}

size_t		sw(t_line *line, size_t *i)
{
	char *s;

	s = line->line;
	while (s[*i] && ft_isspace(s[*i]))
		(*i)++;
	return (*i);
}

t_line		*read_lines(int fd)
{
	size_t	count;
	int		r;
	char	**line;
	t_line	*l[3];

	line = (char **)ft_malloc(sizeof(char *));
	count = 1;
	l[1] = NULL;
	while ((r = get_next_line(fd, line)) > 0)
	{
		l[2] = (t_line *)ft_malloc(sizeof(t_list));
		l[2]->line = *line;
		l[2]->nu = count++;
		l[2]->next = NULL;
		if (l[1] == NULL && (l[1] = l[2]))
			l[0] = l[2];
		else
		{
			l[1]->next = l[2];
			l[1] = l[2];
		}
	}
	free(*line);
	free(line);
	return (l[0]);
}

void		del_comments(t_file *file)
{
	t_line	*line;
	char	*s;

	line = file->lines;
	while (line)
	{
		s = line->line;
		while (*s && *s != COM_C && *s != ';')
			s++;
		while (*s)
		{
			*s = ' ';
			s++;
		}
		line = line->next;
	}
}
