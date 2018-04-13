/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:53:11 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/01/08 20:32:48 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		parse_params(t_token *head, t_token *params, t_ins *ins)
{
	size_t		i;
	int			value;

	i = 0;
	while (params && params->type == TKN_PAR)
	{
		if (params->info / 10 == 0)
		{
			value = params->info == IND_CODE ?
			(ft_atoi(params->str) & 0xffff) : ft_atoi(params->str + 1);
			ins->params[i] = ins->op->short_dir ? value & 0xffff : value;
		}
		else if (params->info / 10 && params->info % 10 == DIR_CODE)
		{
			value = is_label(head, params->str + 2)->info - ins->offset;
			ins->params[i] = ins->op->short_dir ? value & 0xffff : value;
		}
		else if (params->info / 10 && params->info % 10 == IND_CODE)
		{
			value = is_label(head, params->str + 1)->info - ins->offset;
			ins->params[i] = value & 0xffff;
		}
		i++;
		params = params->next;
	}
}

void		put_params(t_file *file)
{
	t_token		*head;
	t_ins		*ins_head;
	t_token		*tkn;

	head = file->tokens;
	ins_head = file->ins;
	tkn = head;
	while (tkn && ins_head)
	{
		if (tkn->type == TKN_INS)
		{
			parse_params(head, tkn->next, ins_head);
			ins_head = ins_head->next;
		}
		tkn = tkn->next;
	}
}
