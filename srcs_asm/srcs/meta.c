/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 23:33:58 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/04/07 16:20:15 by icampill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

/*
** 666 the number of the devil my man !
*/

void			check_rest(char *s)
{
	s++;
	while (ft_isspace(*s))
		s++;
	if (*s != '\0')
		ft_exit("Bad name/comment instruction\n");
}

int				clear_stuff(t_file *file, char *target)
{
	char		*s;
	t_line		*l;

	l = file->lines;
	while (l && ft_strstr(l->line, target) == NULL)
		l = l->next;
	ft_memset(l->line, '#', ft_strlen(target));
	s = ft_strchr(l->line, '"');
	*s = ' ';
	while (l)
	{
		if (*s == '\0' && ((l = l->next) || !l))
		{
			s = l->line;
			continue ;
		}
		if (*s == '"' && (*s = '#'))
			break ;
		*(s++) = ' ';
	}
	return (1);
}

static	int		put_comment(t_file *file)
{
	char		*c;
	char		*s;
	t_line		*l;

	c = file->header.comment;
	l = file->lines;
	while (l && ft_strstr(l->line, COMMENT_CMD_STRING) == NULL)
		l = l->next;
	s = l ? ft_strchr(l->line, '"') : NULL;
	if (!(ext_comment(&s)))
		return (0);
	check_comment(s, l, c, file);
	return (1);
}

static	int		put_name(t_file *file)
{
	char		*c;
	char		*s;
	t_line		*l;
	size_t		i;

	i = 0;
	c = file->header.prog_name;
	l = file->lines;
	while (l && ft_strstr(l->line, NAME_CMD_STRING) == NULL)
		l = l->next;
	s = l ? ft_strchr(l->line, '"') : NULL;
	if (!(ext_name(&s)))
		return (0);
	while (l && *s != '"' && i < PROG_NAME_LENGTH && ++i)
	{
		if (*s == '\0' && ((l = l->next) || !l))
		{
			*(c++) = '\n';
			s = l->line;
			continue ;
		}
		*(c++) = *(s++);
	}
	_(check_rest(s), clear_stuff(file, NAME_CMD_STRING));
	return (1);
}

t_file			*make_file(char *path)
{
	t_file	*ret;

	ret = (t_file *)ft_malloc(sizeof(t_file));
	ft_memset(ret, 0, sizeof(t_file));
	ret->fd = open(path, O_RDONLY);
	if (ret->fd < 0)
		ft_exit("Couldn't open file, ABORT!\n");
	ret->lines = read_lines(ret->fd);
	if (!put_name(ret))
		ft_exit("Name missing, ABORT!\n");
	if (!put_comment(ret))
		ft_exit("Comment missing, ABORT!\n");
	del_comments(ret);
	ret->header.magic = rev_end(COREWAR_EXEC_MAGIC, 4);
	return (ret);
}
