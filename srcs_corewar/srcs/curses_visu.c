/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:57:21 by csimon            #+#    #+#             */
/*   Updated: 2018/02/15 15:57:23 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <ncurses.h>

void	print_stats(t_data_cor *data)
{
	int		line;
	int		i;

	line = 7;
	i = 0;
	mvwprintw(data->w_stats, 3, 1, "Current exec cycle = %d",
		data->current_cycle);
	mvwprintw(data->w_stats, 5, 1, "Processes = %d    ",
		get_nb_proc(data->proc_begin));
	while (i < data->nb_champs)
	{
		print_champ(data, line, (get_next(data, i)));
		line += 4;
		i++;
	}
	lives_breakdown(data, &line);
	mvwprintw(data->w_stats, line, 1, "Lives in current period: %d           ",
		data->total_lives);
	mvwprintw(data->w_stats, line + 2, 1, "Lives in all periods: %d          ",
		data->total_lives_all);
	mvwprintw(data->w_stats, line + 4, 1, "Cycle to die: %d  ",
		data->cycles_to_die);
	mvwprintw(data->w_stats, line + 6, 1, "Cycle Delta: %d  ", CYCLE_DELTA);
	mvwprintw(data->w_stats, line + 8, 1, "Max Checks: %d ", data->max_checks);
	mvwprintw(data->w_stats, line + 10, 1, "NBR LIVE: %d ", NBR_LIVE);
}

void	set_pc(t_data_cor *data, int code)
{
	t_proc *tmp;

	tmp = data->proc_begin;
	while (tmp != NULL)
	{
		if (code == 1)
		{
			if ((data->arena_color[(tmp->start_index + (tmp->pc))
				% MEM_SIZE]) < 5)
			{
				data->arena_color[(tmp->start_index + (tmp->pc))
					% MEM_SIZE] += 5;
			}
		}
		else if (code == 0 && (data->arena_color[(tmp->start_index +
			(tmp->pc)) % MEM_SIZE]) >= 5)
			data->arena_color[(tmp->start_index + (tmp->pc)) % MEM_SIZE] -= 5;
		tmp = tmp->next;
	}
}

void	end_war(t_data_cor *data)
{
	int		i;
	int		winner;

	winner = 0xffffffff - data->last_champ_alive;
	i = 0;
	mvwprintw(data->w_stats, 1, 1, "**FINISHED** ");
	while (i < 4)
	{
		if (data->all_the_champ[i].player_num == winner)
		{
			mvwprintw(data->w_stats, 62, 1, "Le joueur %d (",
				0 - data->last_champ_alive);
			wattron(data->w_stats, COLOR_PAIR(i + 1));
			wprintw(data->w_stats, "%s",
				data->all_the_champ[i].header->prog_name);
			wattroff(data->w_stats, COLOR_PAIR(i + 1));
			wprintw(data->w_stats, ") a gagné\n");
		}
		i++;
	}
	mvwprintw(data->w_stats, 64, 1, "PRESS DOWN TO EXIT");
	wrefresh(data->w_stats);
	while ((wgetch(data->w_arena)) != KEY_DOWN)
		;
}

int		set_speed(t_data_cor *data)
{
	static int	time = 100000;
	static int	pause = 0;
	int			ch;

	ch = wgetch(data->w_arena);
	if (ch == KEY_DOWN)
		pause = 0;
	if (pause == 0)
		mvwprintw(data->w_stats, 1, 1, "**PAUSED** ");
	else
		mvwprintw(data->w_stats, 1, 1, "**RUNNING**");
	if ((ch != KEY_DOWN && pause == 0))
	{
		pause = 1;
		wrefresh(data->w_stats);
		while ((ch = wgetch(data->w_arena)) != KEY_DOWN)
			;
	}
	if (ch == KEY_LEFT && time <= 150000)
		time += 5000;
	if (ch == KEY_RIGHT && time >= 5000)
		time -= 5000;
	mvwprintw(data->w_stats, 55, 1, "Time %d            ", time);
	return (time);
}

void	spectate_battle(t_data_cor *data, int code)
{
	int			time;

	curs_set(0);
	if (code == 0)
	{
		data->cycles_to_die = 0;
		print_stats(data);
		end_war(data);
		return ;
	}
	set_pc(data, 1);
	print_arena(data);
	set_pc(data, 0);
	print_stats(data);
	time = set_speed(data);
	wrefresh(data->w_arena);
	wrefresh(data->w_stats);
	if (time != 0)
		usleep(time);
	wrefresh(data->w_arena);
	wrefresh(data->w_stats);
}
