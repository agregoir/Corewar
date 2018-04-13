/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 19:02:01 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/12/27 12:00:16 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_lines(t_file *file)
{
	t_line	*lines;

	lines = file->lines;
	while (lines)
	{
		ft_printf("%zu :%s\n", lines->nu, lines->line);
		lines = lines->next;
	}
}

void	print_tokens(t_token *head)
{
	while (head)
	{
		ft_printf("[type = %d] [value = %s] [info = %d] \
				[index = %zu] [line = %zu]\n",
				(int)head->type, head->str, head->info, head->i, head->lnu);
		head = head->next;
	}
}

void	print_line(t_line *lines, size_t lnu)
{
	while (lines)
	{
		if (lines->nu == lnu)
			break ;
		lines = lines->next;
	}
	ft_printf("%s\n", lines->line);
}

void	print_ins(t_ins *ins, t_line *lines)
{
	t_token		*tkn;

	while (ins)
	{
		tkn = ins->tkn;
		ft_printf("\n{%s (%x | %zx) [%02x, %02x, %02x]\
		- [%d, %d, %d] - %zu %x}\t",
			ins->op->label, ins->op->op_code, ins->ocp, ins->params[0],
			ins->params[1], ins->params[2],
			ins->para_size[0], ins->para_size[1], ins->para_size[2],
			ins->size, ins->offset + 0x00000890);
		print_line(lines, ins->tkn->lnu);
		tkn = tkn->next;
		while (tkn && tkn->type != TKN_INS)
		{
			ft_printf("[type = %d] [value = %s] [info = %d]\
			[index = %zu] [line = %zu]\t",
			(int)tkn->type, tkn->str, tkn->info, tkn->i, tkn->lnu);
			tkn = tkn->next;
		}
		ins = ins->next;
	}
}
