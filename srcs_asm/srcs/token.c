/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:46:49 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/01/08 16:05:13 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_token		*token_label(t_token *last, t_line *line, size_t *i)
{
	t_token	*ret;
	size_t	j;
	char	*s;

	sw(line, i);
	j = *i;
	s = line->line;
	ret = NULL;
	while (s[j] && is_label_char(s[j]))
		j++;
	if (s[j] == ':')
	{
		ret = (t_token *)ft_malloc(sizeof(t_token));
		ret->type = TKN_LBL;
		ret->lnu = line->nu;
		ret->i = *i;
		ret->str = ft_strsub(s, *i, j - *i);
		*i = ++j;
	}
	sw(line, i);
	if (last)
		last->next = ret;
	return (ret ? ret : last);
}

t_token		*token_ins(t_token *last, t_line *line, size_t *i)
{
	t_token			*ret;
	size_t			j;
	char			*s;

	j = *i;
	s = line->line;
	ret = NULL;
	while (s[j] && ft_isalpha(s[j]))
		j++;
	if (j > *i)
	{
		ret = (t_token *)ft_malloc(sizeof(t_token));
		ret->type = TKN_INS;
		ret->lnu = line->nu;
		ret->i = *i;
		ret->str = ft_strsub(s, *i, j - *i);
		*i = j;
	}
	sw(line, i);
	if (last)
		last->next = ret;
	return (ret ? ret : last);
}

t_token		*token_param(t_token *last, t_line *line, size_t *i)
{
	t_token	*ret;
	size_t	j;
	char	*s;

	j = *i;
	s = line->line;
	while (s[j] && is_param_char(s[j]))
		j++;
	if ((ret = NULL) || j > *i)
	{
		ret = (t_token *)ft_malloc(sizeof(t_token));
		ret->type = TKN_PAR;
		ret->lnu = line->nu;
		ret->i = *i;
		ret->str = ft_strsub(s, *i, j - *i);
		_(*i = j, sw(line, i));
	}
	if (!ret || (s[*i] && s[*i] != ',')
		|| (s[(*i)++] == ',' && sw(line, i) && !s[*i]))
		_(ft_printf("Error in line %zu\n", line->nu), ft_exit("ABORT!\n"));
	if (last)
		last->next = ret;
	return (ret ? ret : last);
}

t_token		*tokenize(t_file *file)
{
	t_token	*head;
	t_token	*last;
	t_line	*lines;
	size_t	i;

	lines = file->lines;
	head = NULL;
	last = NULL;
	while (lines)
	{
		i = 0;
		if (!head && (last = token_label(last, lines, &i)))
			head = last;
		else
			last = token_label(last, lines, &i);
		if (!head && (last = token_ins(last, lines, &i)))
			head = last;
		else
			last = token_ins(last, lines, &i);
		while (lines->line[i])
			_(last = token_param(last, lines, &i), sw(lines, &i));
		lines = lines->next;
	}
	return (head);
}
