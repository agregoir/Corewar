/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:13:47 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/04/07 16:22:45 by icampill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
** CCCBBBAAA
** third|second|first
*/

t_op	g_op_tab[17] =
{
	{"live", 1, 0b010, 1, 0, 0},
	{"ld", 2, 0b001110, 2, 1, 0},
	{"st", 2, 0b101001, 3, 1, 0},
	{"add", 3, 0b001001001, 4, 1, 0},
	{"sub", 3, 0b001001001, 5, 1, 0},
	{"and", 3, 0b001111111, 6, 1, 0},
	{"or", 3, 0b001111111, 7, 1, 0},
	{"xor", 3, 0b001111111, 8, 1, 0},
	{"zjmp", 1, 0b010, 9, 0, 1},
	{"ldi", 3, 0b001011111, 10, 1, 1},
	{"sti", 3, 0b011111001, 11, 1, 1},
	{"fork", 1, 0b010, 12, 0, 1},
	{"lld", 2, 0b001110, 13, 1, 0},
	{"lldi", 3, 0b001011111, 14, 1, 1},
	{"lfork", 1, 0b010, 15, 0, 1},
	{"aff", 1, 0b001, 16, 1, 0},
	{0, 0, 0, 0, 0, 0}
};

t_token		*is_label(t_token *head, char *label)
{
	while (head)
	{
		if (head->type == TKN_LBL && ft_strcmp(head->str, label) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

int			ext_comment(char **s)
{
	if (!(*s))
		ft_exit("Bad comment\n");
	else
		(*(s))++;
	return (1);
}

void		check_comment(char *s, t_line *l, char *c, t_file *file)
{
	size_t	i;

	i = 0;
	while (l && *s != '"' && i < COMMENT_LENGTH && ++i)
	{
		if (*s == '\0' && ((l = l->next) || !l))
		{
			*(c++) = '\n';
			s = l->line;
			continue ;
		}
		if (!l->next)
			ft_exit("bad comment");
		*(c++) = *(s++);
	}
	_(check_rest(s), clear_stuff(file, COMMENT_CMD_STRING));
}

int			ext_name(char **s)
{
	if (!(*s))
		ft_exit("Bad name\n");
	else
		(*s)++;
	if ((!ft_strchr((*s), '"') && ft_exit("Bad name\n")))
		return (0);
	return (1);
}
