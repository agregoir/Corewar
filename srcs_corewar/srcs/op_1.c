/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:43:28 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:43:30 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		live_for_visu(t_data_cor *data, int playnum, t_proc *tmp, int i)
{
	if (data->is_visual == 1)
	{
		data->arena_bright[(tmp->start_index + tmp->pc) % MEM_SIZE] =
		-(data->nb_champs * 20) - (data->champ_color[i] - 1);
		mvwprintw(data->w_stats, 60, 1, "Le joueur %d (", 0 - playnum);
		wattron(data->w_stats, COLOR_PAIR(data->champ_color[i]));
		wprintw(data->w_stats, "%s", data->all_the_champ[i].header->prog_name);
		wattroff(data->w_stats, COLOR_PAIR(data->champ_color[i]));
		wprintw(data->w_stats, ") est en vie			");
	}
}

void		live_op(t_data_cor *data, t_proc *tmp)
{
	int		i;
	int		playnum;

	playnum = 0;
	tmp->nbr_live++;
	data->total_lives++;
	data->total_lives_all++;
	playnum = get_playernum(data, &data->arena[(tmp->start_index
		+ tmp->pc + 1) % MEM_SIZE], 4);
	i = 0;
	while (i < data->nb_champs)
	{
		if (data->champ_lives[i] == playnum)
		{
			data->last_champ_alive = playnum;
			data->all_the_champ[i].nbr_lives++;
			data->all_the_champ[i].last_live = data->current_cycle;
			live_for_visu(data, playnum, tmp, i);
		}
		i++;
	}
	tmp->current_op = -1;
	tmp->pc += 5;
}

void		ft_ld(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	unsigned short	*pc;

	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0],
		data->arena[((tmp->start_index + tmp->pc + 1) % MEM_SIZE)], pc, 0);
	if (check_ocp(ocp_tab, g_op_tab[1].params, 2))
	{
		if (ocp_tab[0][0] == 4)
			tmp->regs[ocp_tab[1][1] - 1] = fetch_value(data,
				tmp, (short)ocp_tab[0][1]);
		else
			tmp->regs[ocp_tab[1][1] - 1] = ocp_tab[0][1];
		if (tmp->regs[ocp_tab[1][1] - 1] == 0)
			tmp->carry = 1;
		else
			tmp->carry = 0;
	}
	tmp->pc += end_op(tmp, ocp_tab, 0, 2);
}

void		ft_st(t_data_cor *data, t_proc *tmp)
{
	int				**ocp_tab;
	unsigned short	*pc;

	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0],
		data->arena[((tmp->start_index + tmp->pc + 1) % MEM_SIZE)], pc, 0);
	if (check_ocp(ocp_tab, g_op_tab[2].params, 2))
	{
		if (ocp_tab[1][0] == 1)
			tmp->regs[ocp_tab[1][1] - 1] = tmp->regs[ocp_tab[0][1] - 1];
		else if (ocp_tab[1][0] == 4)
			write_value(data, tmp, (short)ocp_tab[1][1],
				tmp->regs[ocp_tab[0][1] - 1]);
	}
	tmp->pc += end_op(tmp, ocp_tab, 0, 2);
}

void		ft_add(t_data_cor *data, t_proc *tmp)
{
	int				arg_1;
	int				arg_2;
	int				sum;
	int				**ocp_tab;
	unsigned short	*pc;

	pc = (unsigned short *)&data->arena[(tmp->start_index + tmp->pc)
		% MEM_SIZE];
	ocp_tab = call_ocp(&data->arena[0],
		data->arena[((tmp->start_index + tmp->pc + 1) % MEM_SIZE)], pc, 0);
	if (check_ocp(ocp_tab, g_op_tab[3].params, 3))
	{
		arg_1 = tmp->regs[ocp_tab[0][1] - 1];
		arg_2 = tmp->regs[ocp_tab[1][1] - 1];
		sum = arg_1 + arg_2;
		tmp->regs[ocp_tab[2][1] - 1] = sum;
		if (sum == 0)
			tmp->carry = 1;
		else
			tmp->carry = 0;
	}
	tmp->pc += end_op(tmp, ocp_tab, 0, 3);
}
