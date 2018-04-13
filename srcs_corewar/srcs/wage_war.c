/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wage_war.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 09:21:34 by agregoir          #+#    #+#             */
/*   Updated: 2018/03/04 15:42:13 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_lives(t_proc **begin, t_data_cor *data)
{
	int		lives;
	t_proc	*tmp;
	t_proc	*swap;

	lives = 0;
	tmp = *begin;
	swap = tmp;
	while (swap != NULL)
	{
		swap = tmp->next;
		if (tmp->nbr_live == 0)
		{
			if (kill_proc(begin, tmp) == NULL)
				break ;
		}
		else
			tmp->nbr_live = 0;
		tmp = swap;
	}
	lives = data->total_lives;
	deal_data_lives(data);
	if (lives >= NBR_LIVE)
		data->max_checks = MAX_CHECKS;
	return (lives);
}

int		manage_cycles(t_data_cor *data)
{
	static int	micro_cycle = 0;
	static int	live_status = 0;

	if (data->current_cycle == 0)
		return (data->current_cycle += 1);
	data->current_cycle += 1;
	micro_cycle += 1;
	if (micro_cycle == data->cycles_to_die)
	{
		data->period_elapsed = 1;
		micro_cycle = 0;
		if ((live_status = check_lives(&data->proc_begin, data)) >= NBR_LIVE)
			data->cycles_to_die -= CYCLE_DELTA;
		else
			data->max_checks--;
		if (live_status == 0 || data->cycles_to_die <= 0)
			return (-1);
	}
	if (data->max_checks == 0)
	{
		if ((data->cycles_to_die -= CYCLE_DELTA) <= 0)
			return (-1);
		data->max_checks = MAX_CHECKS;
	}
	return (0);
}

void	announce_winner(t_data_cor *data, int last_player)
{
	int		i;
	int		winner;

	i = 0;
	winner = 0xffffffff - last_player;
	while (i < 4)
	{
		if (data->all_the_champ[i].player_num == winner)
			ft_printf("Contestant %d, \"%s\", has won !\n",
				0 - last_player, data->all_the_champ[i].header->prog_name);
		i++;
	}
}

void	start_war(t_data_cor *data)
{
	t_proc	*tmp;

	data->current_cycle = 0;
	while (data->proc_begin != NULL && data->current_cycle != data->dump_cycles)
	{
		if (data->is_visual == 1)
			spectate_battle(data, 1);
		if (manage_cycles(data) == -1)
		{
			if (data->is_visual == 1)
				spectate_battle(data, 0);
			break ;
		}
		tmp = data->proc_begin;
		while (tmp != NULL)
		{
			check_op(data, tmp);
			tmp = tmp->next;
		}
	}
	if (data->current_cycle >= data->dump_cycles && data->dump_cycles != -1)
		dump_stuff(data);
	if (data->is_visual != 1)
		announce_winner(data, data->last_champ_alive);
}
