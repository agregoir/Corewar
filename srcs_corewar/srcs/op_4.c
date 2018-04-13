/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:43:45 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:43:47 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_lld(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	unsigned short	*pc;

	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0], data->arena[((tmp->start_index +
	tmp->pc + 1) % MEM_SIZE)], pc, 0);
	if (check_ocp(ocp_tab, g_op_tab[12].params, 2))
	{
		if (ocp_tab[0][0] == 4)
			tmp->regs[ocp_tab[1][1] - 1] =
		fetch_l_value(data, tmp, (short)ocp_tab[0][1]);
		else
			tmp->regs[ocp_tab[1][1] - 1] = ocp_tab[0][1];
		if (tmp->regs[ocp_tab[1][1] - 1] == 0)
			tmp->carry = 1;
		else
			tmp->carry = 0;
	}
	tmp->pc += end_op(tmp, ocp_tab, 0, 2);
}

void		ft_lldi(t_data_cor *d, t_proc *tmp)
{
	int				**ocp_tab;
	unsigned int	arg[3];
	unsigned short	*pc;

	arg[2] = 0;
	pc = (unsigned short *)&d->arena[(tmp->start_index + tmp->pc) % MEM_SIZE];
	ocp_tab = call_ocp(&d->arena[0], d->arena[((tmp->start_index +
		tmp->pc + 1) % MEM_SIZE)], pc, 1);
	if (check_ocp(ocp_tab, g_op_tab[13].params, 3))
	{
		while (arg[2] < 2)
		{
			if (ocp_tab[arg[2]][0] == 1)
				arg[arg[2]] = tmp->regs[ocp_tab[arg[2]][1] - 1];
			else if (ocp_tab[arg[2]][0] == 4 && arg[2] == 0)
				arg[arg[2]] = fetch_value(d, tmp, (short)ocp_tab[arg[2]][1]);
			else
				arg[arg[2]] = (short)ocp_tab[arg[2]][1];
			arg[2]++;
		}
		tmp->regs[ocp_tab[2][1] - 1] = fetch_l_value(d, tmp,
			(arg[0] + arg[1]));
		tmp->carry = (tmp->regs[ocp_tab[2][1] - 1] == 0) ? (1) : (0);
	}
	tmp->pc += end_op(tmp, ocp_tab, 1, 3);
}

void		ft_lfork(t_data_cor *data, t_proc *tmp)
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
		if (fiston->pc + ((short)arg) < 0)
			fiston->pc += MEM_SIZE;
		fiston->pc += (short)arg;
	}
	else
		fiston->pc += arg;
	tmp->pc += 3;
	fiston->current_op = -1;
	tmp->current_op = -1;
	data->proc_begin = add_proc(fiston, &data->proc_begin);
}

void		ft_aff(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	int				aff;
	unsigned short	*pc;

	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0], data->arena[((tmp->start_index +
		tmp->pc + 1) % MEM_SIZE)], pc, 1);
	if (check_ocp(ocp_tab, g_op_tab[15].params, 1))
		aff = tmp->regs[data->arena[(tmp->start_index + tmp->pc +
		2) % MEM_SIZE] - 1];
	tmp->pc += end_op(tmp, ocp_tab, 0, 1);
}
