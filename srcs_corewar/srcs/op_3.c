/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:43:39 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:43:41 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_zjmp(t_data_cor *data, t_proc *tmp)
{
	short	arg;

	arg = 0;
	if (tmp->carry == 1)
	{
		arg = data->arena[(tmp->start_index + tmp->pc + 1) % MEM_SIZE];
		arg = arg << 8;
		arg += data->arena[(tmp->start_index + tmp->pc + 2) % MEM_SIZE];
		if (tmp->pc + (arg % IDX_MOD) < 0)
			tmp->pc += MEM_SIZE;
		tmp->pc += (arg % IDX_MOD);
	}
	else
		tmp->pc += 3;
	tmp->current_op = -1;
}

void		ft_ldi(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	int				arg_1;
	int				arg_2;
	unsigned short	*pc;

	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0], data->arena[((tmp->start_index +
	tmp->pc + 1) % MEM_SIZE)], pc, 1);
	if (check_ocp(ocp_tab, g_op_tab[9].params, 3))
	{
		if (ocp_tab[0][0] == 1)
			arg_1 = tmp->regs[ocp_tab[0][1] - 1];
		else if (ocp_tab[0][0] == 4)
			arg_1 = fetch_value(data, tmp, (short)ocp_tab[0][1]);
		else
			arg_1 = (short)ocp_tab[0][1];
		if (ocp_tab[1][0] == 1)
			arg_2 = tmp->regs[ocp_tab[1][1] - 1];
		else
			arg_2 = (short)ocp_tab[1][1];
		tmp->regs[ocp_tab[2][1] - 1] = fetch_value(data, tmp, (arg_1 + arg_2));
	}
	tmp->pc += end_op(tmp, ocp_tab, 1, 3);
}

void		ft_sti(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	int				arg_1;
	int				arg_2;
	unsigned short	*pc;

	arg_1 = 0;
	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0], data->arena[((tmp->start_index +
		tmp->pc + 1) % MEM_SIZE)], pc, 1);
	if (check_ocp(ocp_tab, g_op_tab[10].params, 3))
	{
		if (ocp_tab[1][0] == 1)
			arg_1 = tmp->regs[ocp_tab[1][1] - 1];
		else if (ocp_tab[1][0] == 4)
			arg_1 = fetch_value(data, tmp, (short)ocp_tab[1][1]);
		else if (ocp_tab[1][0] == 2)
			arg_1 = (short)ocp_tab[1][1];
		if (ocp_tab[2][0] == 1)
			arg_2 = tmp->regs[ocp_tab[2][1] - 1];
		else
			arg_2 = (short)ocp_tab[2][1];
		write_value(data, tmp, (arg_1 + arg_2), tmp->regs[ocp_tab[0][1] - 1]);
	}
	tmp->pc += end_op(tmp, ocp_tab, 1, 3);
}

void		ft_fork(t_data_cor *data, t_proc *tmp)
{
	t_proc			*fiston;
	unsigned short	arg;

	if ((fiston = (t_proc *)ft_memalloc(sizeof(t_proc))) == NULL)
		ft_error(ALLOC_FAILED);
	copie_cette_merde(fiston, tmp);
	arg = 0;
	arg = data->arena[(tmp->start_index + tmp->pc + 1) % MEM_SIZE];
	arg = arg << 8;
	arg += data->arena[(tmp->start_index + tmp->pc + 2) % MEM_SIZE];
	if (arg > 0x8000)
	{
		if (fiston->pc + ((short)arg % IDX_MOD) < 0)
			fiston->pc += MEM_SIZE;
		fiston->pc += (short)arg % IDX_MOD;
	}
	else
		fiston->pc += arg % IDX_MOD;
	tmp->pc += 3;
	fiston->current_op = -1;
	tmp->current_op = -1;
	data->proc_begin = add_proc(fiston, &data->proc_begin);
}
