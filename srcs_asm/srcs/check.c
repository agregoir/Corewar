/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:28:35 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/01/08 13:56:26 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			check_ins(t_file *file)
{
	char		ret;
	t_token		*head;

	head = file->tokens;
	while (head)
	{
		if (head->type == TKN_INS)
		{
			ret = 0;
			while (ret < 16)
			{
				if (ft_strcmp(head->str, (g_op_tab[(size_t)ret]).label) == 0)
				{
					head->info = ret;
					break ;
				}
				ret++;
			}
			head->info = ret == 16 ? -1 : head->info;
			if (ret == 16)
				_(ft_printf("Bad instruction line %zu\n", head->lnu), exit(0));
		}
		head = head->next;
	}
}

static char		is_dir(t_token *head, t_token *param)
{
	char	*s;

	s = param->str;
	if (*s == D_C && is_number(s + 1) && (param->info = DIR_CODE))
		return (1);
	else if (*s == D_C && *(s + 1) == L_C && is_label(head, s + 2)
			&& (param->info = DIR_CODE + 10))
		return (1);
	return (0);
}

static char		is_ind(t_token *head, t_token *param)
{
	char	*s;

	s = param->str;
	if (*s == L_C && is_label(head, s + 1) && (param->info = IND_CODE + 10))
		return (1);
	else
		return (is_number(s) && (param->info = IND_CODE));
}

static char		is_reg(t_token *param)
{
	char	*s;
	int		val;

	s = param->str;
	if (*s == 'r' && (val = ft_atoi(s + 1)) <= 16 && val
		&& ((val < 10 && *(s + 2) == 0) || (val > 9 && *(s + 3) == 0))
		&& (param->info = REG_CODE))
		return (1);
	return (0);
}

void			check_param(t_file *file)
{
	t_token		*head;
	t_token		*tkn;

	head = file->tokens;
	tkn = file->tokens;
	while (tkn)
	{
		if (tkn->type == TKN_PAR)
		{
			if (!is_reg(tkn) && !is_dir(head, tkn) && !is_ind(head, tkn))
			{
				ft_printf("Problem in line %zu index %zu\n", tkn->lnu, tkn->i);
				ft_exit("ABORT!\n");
			}
		}
		tkn = tkn->next;
	}
}
