/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:25:45 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/12/22 19:30:50 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void			set_ocp(t_token *tkn, t_ins *ins)
{
	t_token			*params;
	size_t			ocp;
	size_t			i;

	i = 0;
	params = tkn->next;
	ocp = 0;
	while (params && params->type == TKN_PAR)
	{
		ocp = (ocp << 2) | (params->info % 10);
		if (params->info % 10 == DIR_CODE && (ins->size += DIR_SIZE))
			ins->para_size[i] = DIR_SIZE;
		else if (params->info % 10 == IND_CODE && (ins->size += IND_SIZE))
			ins->para_size[i] = IND_SIZE;
		else if (params->info % 10 == REG_CODE && (ins->size += REG_SIZE))
			ins->para_size[i] = REG_SIZE;
		params = params->next;
		i++;
	}
	i = 3 - ins->op->num_params + 1;
	ins->ocp = ins->op->coding_param ? ocp << (2 * i) : 0;
	ins->size += ins->op->coding_param + 1;
}

static char			valid_params(t_token *tkn, t_ins *ins)
{
	unsigned int	num;
	unsigned int	types;

	num = 0;
	types = ins->op->types;
	while (tkn && tkn->type == TKN_PAR && types)
	{
		if (!((types & 0xfff) & 0b001) && tkn->info % 10 == REG_CODE)
			return (0);
		if (!((types & 0xfff) & 0b010) && tkn->info % 10 == DIR_CODE)
			return (0);
		if (!((types & 0xfff) & 0b100) && tkn->info % 10 == IND_CODE)
			return (0);
		types = types >> 3;
		num++;
		tkn = tkn->next;
	}
	return (num == ins->op->num_params ? 1 : 0);
}

t_ins				*ins(t_token *tkn)
{
	t_ins			*ret;

	ret = (t_ins *)ft_malloc(sizeof(t_ins));
	ret->op = g_op_tab + tkn->info;
	ret->tkn = tkn;
	if (!valid_params(tkn->next, ret))
		return (NULL);
	set_ocp(tkn, ret);
	ret->next = NULL;
	return (ret);
}

t_ins				*gen_ins(t_file *file)
{
	t_token			*head;
	t_ins			*fst_ins;
	t_ins			*lst_ins;
	t_ins			*new_ins;
	size_t			offset;

	head = file->tokens;
	offset = 0;
	fst_ins = NULL;
	lst_ins = NULL;
	while (head)
	{
		head->info = head->type == TKN_LBL ? offset : head->info;
		if (head->type == TKN_INS)
		{
			if (!(new_ins = ins(head)))
				_(ft_printf("problem in line %zu\n", head->lnu), exit(0));
			new_ins->offset = offset;
			fst_ins = !(offset += new_ins->size) || fst_ins ? fst_ins : new_ins;
			lst_ins ? (lst_ins->next = new_ins) : NULL;
			lst_ins = new_ins;
		}
		head = head->next;
	}
	return (fst_ins);
}
