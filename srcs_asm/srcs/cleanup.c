/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icampill <icampill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:49:25 by icampill          #+#    #+#             */
/*   Updated: 2018/04/07 17:06:07 by icampill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	free_lines(t_line *line)
{
	t_line *tmp;

	while (line)
	{
		free(line->line);
		tmp = line;
		line = line->next;
		free(tmp);
	}
}

static void	free_token(t_token *token)
{
	t_token *tmp;

	while (token)
	{
		free(token->str);
		tmp = token;
		token = token->next;
		free(tmp);
	}
}

static void	free_ins(t_ins *ins)
{
	t_ins	*tmp;

	while (ins)
	{
		tmp = ins;
		ins = ins->next;
		free(tmp);
	}
}

void		free_file(t_file *file)
{
	free_lines(file->lines);
	free_token(file->tokens);
	free_ins(file->ins);
	free(file);
}
