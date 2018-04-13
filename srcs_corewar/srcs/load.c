/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 10:59:25 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 10:59:29 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	load_champ(t_data_cor *data, int champnum, t_champion *champ)
{
	static int	space = 0;
	t_proc		*new_proc;
	int			start_index;

	if (data->is_visual != 1)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			space + 1, champ->prog_size, champ->header->prog_name,
			champ->header->comment);
	start_index = ((MEM_SIZE / champnum) * space);
	new_proc = init_proc(champ, start_index);
	data->proc_begin = add_proc(new_proc, &(data->proc_begin));
	ft_memcpy(&data->arena[start_index], champ->code_part, champ->prog_size);
	ft_memset(&data->arena_color[start_index], new_proc->color,
		champ->prog_size);
	data->champ_color[space] = new_proc->color;
	data->champ_lives[space] = new_proc->player_num;
	champ->order = space;
	space++;
	data->nb_champs++;
	data->last_champ_alive = new_proc->player_num;
}

int		which_next(t_champion champ[4], int champnum)
{
	int			i;
	int			high;
	static int	save = -10;

	i = 0;
	high = PLAYER_NUM_MAX;
	while (i < champnum)
	{
		if (champ[i].player_num <= high && champ[i].player_num > save)
			high = champ[i].player_num;
		i++;
	}
	if (high == save)
		return (5);
	i = 0;
	while (champ[i].player_num != high && i < champnum - 1)
		i++;
	save = high;
	return (i);
}

int		find_next_free(t_champion champs[4], int to_change)
{
	int		i;
	int		index;

	index = 0;
	i = 0;
	while (index < 4)
	{
		if (champs[index].player_num == to_change)
		{
			to_change += 1;
			index = -1;
		}
		index++;
	}
	return (to_change);
}

void	solve_double(t_champion chp[4])
{
	int		i;
	int		check;
	int		s;

	s = 1;
	check = 0;
	i = 0;
	while (i < 4)
	{
		check = chp[i].player_num;
		if (check == -1)
			chp[i].player_num = find_next_free(chp, chp[i].player_num);
		while (s < 4)
		{
			if (chp[s].player_num == check
				|| chp[s].player_num == -1)
				while (chp[s].player_num == check
					|| chp[s].player_num == -1)
					chp[s].player_num = find_next_free(chp, chp[s].player_num);
			s++;
		}
		i++;
		s = i + 1;
	}
}

void	pre_loading(t_champion *all_the_champ, int champnum, t_data_cor *data)
{
	int		i;
	int		champ_i;

	if (champnum > 4)
		ft_error(ERROR_TOO_MANY_CHAMPS);
	solve_double(all_the_champ);
	champ_i = 0;
	i = champnum;
	if (data->is_visual != 1)
		ft_printf("Introducing contestants...\n");
	while (i)
	{
		if ((champ_i = which_next(all_the_champ, champnum)) != 4)
			load_champ(data, champnum, &all_the_champ[champ_i]);
		i--;
	}
}
