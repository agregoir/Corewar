/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:42:13 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:42:18 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_op(t_proc *tmp, unsigned char *str)
{
	tmp->pc_index = str;
	tmp->current_op = (int)str[0];
	if (tmp->current_op > 0 && tmp->current_op < 17)
		tmp->current_exec_cycle = g_op_tab[(tmp->current_op) - 1].cycles;
	else
		tmp->current_exec_cycle = -1;
}

void	execute_op(t_data_cor *data, t_proc *tmp, unsigned char *str)
{
	int		i;
	int		current_op;

	current_op = (int)str[0];
	i = 0;
	if (tmp->current_op > 16 || tmp->current_op <= 0)
		return ;
	while ((int)g_fct_tab[i].op_code != tmp->current_op)
		i++;
	if (i > 16)
	{
		tmp->pc += 1;
		return ;
	}
	else
		g_fct_tab[i].ptr(data, tmp);
}

void	check_op(t_data_cor *data, t_proc *tmp)
{
	if (tmp->current_op == -1)
	{
		get_op(tmp, &data->arena[((tmp->start_index) + tmp->pc) % MEM_SIZE]);
		if (tmp->current_exec_cycle == -1)
		{
			tmp->pc += 1;
			tmp->current_op = -1;
			return ;
		}
		tmp->current_exec_cycle -= 1;
	}
	else if (tmp->current_op == 0 || tmp->current_op > 16)
	{
		tmp->pc += 1;
	}
	else
		tmp->current_exec_cycle -= 1;
	if (tmp->current_exec_cycle == 0)
		execute_op(data, tmp,
			&data->arena[(tmp->start_index + tmp->pc) % MEM_SIZE]);
}
