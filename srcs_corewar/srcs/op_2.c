/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:43:35 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:43:36 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_sub(t_data_cor *data, t_proc *tmp)
{
	int				arg_1;
	int				arg_2;
	int				sub;
	int				**ocp_tab;
	unsigned short	*pc;

	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0], data->arena[((tmp->start_index +
		tmp->pc + 1) % MEM_SIZE)], pc, 0);
	if (check_ocp(ocp_tab, g_op_tab[4].params, 3))
	{
		arg_1 = tmp->regs[ocp_tab[0][1] - 1];
		arg_2 = tmp->regs[ocp_tab[1][1] - 1];
		sub = arg_1 - arg_2;
		tmp->regs[ocp_tab[2][1] - 1] = sub;
		if (sub == 0)
			tmp->carry = 1;
		else
			tmp->carry = 0;
	}
	tmp->pc += end_op(tmp, ocp_tab, 0, 3);
}

void		ft_and(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	unsigned int	a[3];
	unsigned short	*pc;

	a[2] = 0;
	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0], data->arena[((tmp->start_index +
		tmp->pc + 1) % MEM_SIZE)], pc, 0);
	if (check_ocp(ocp_tab, g_op_tab[7].params, 3))
	{
		while (a[2] < 2)
		{
			if (ocp_tab[a[2]][0] == 1)
				a[a[2]] = tmp->regs[ocp_tab[a[2]][1] - 1];
			else
				(ocp_tab[a[2]][0] == 4) ? (a[a[2]] = fetch_value(data, tmp,
					(short)ocp_tab[a[2]][1])) : (a[a[2]] = ocp_tab[a[2]][1]);
			a[2]++;
		}
		tmp->regs[ocp_tab[2][1] - 1] = a[0] & a[1];
		tmp->carry = (tmp->regs[ocp_tab[2][1] - 1] == 0) ? (1) : (0);
	}
	tmp->pc += end_op(tmp, ocp_tab, 0, 3);
}

void		ft_or(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	unsigned int	a[3];
	unsigned short	*pc;

	a[2] = 0;
	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0], data->arena[((tmp->start_index +
		tmp->pc + 1) % MEM_SIZE)], pc, 0);
	if (check_ocp(ocp_tab, g_op_tab[7].params, 3))
	{
		while (a[2] < 2)
		{
			if (ocp_tab[a[2]][0] == 1)
				a[a[2]] = tmp->regs[ocp_tab[a[2]][1] - 1];
			else
				(ocp_tab[a[2]][0] == 4) ? (a[a[2]] = fetch_value(data, tmp,
					(short)ocp_tab[a[2]][1])) : (a[a[2]] = ocp_tab[a[2]][1]);
			a[2]++;
		}
		tmp->regs[ocp_tab[2][1] - 1] = a[0] | a[1];
		tmp->carry = (tmp->regs[ocp_tab[2][1] - 1] == 0) ? (1) : (0);
	}
	tmp->pc += end_op(tmp, ocp_tab, 0, 3);
}

void		ft_xor(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	unsigned int	a[3];
	unsigned short	*pc;

	a[2] = 0;
	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0], data->arena[((tmp->start_index +
		tmp->pc + 1) % MEM_SIZE)], pc, 0);
	if (check_ocp(ocp_tab, g_op_tab[7].params, 3))
	{
		while (a[2] < 2)
		{
			if (ocp_tab[a[2]][0] == 1)
				a[a[2]] = tmp->regs[ocp_tab[a[2]][1] - 1];
			else
				(ocp_tab[a[2]][0] == 4) ? (a[a[2]] = fetch_value(data, tmp,
					(short)ocp_tab[a[2]][1])) : (a[a[2]] = ocp_tab[a[2]][1]);
			a[2]++;
		}
		tmp->regs[ocp_tab[2][1] - 1] = a[0] ^ a[1];
		tmp->carry = (tmp->regs[ocp_tab[2][1] - 1] == 0) ? (1) : (0);
	}
	tmp->pc += end_op(tmp, ocp_tab, 0, 3);
}
