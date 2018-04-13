/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses_visu_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:42:38 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:42:41 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <ncurses.h>

void	print_line_last(t_data_cor *data, int str[48], int i)
{
	while (i < 48)
	{
		wattron(data->w_stats, COLOR_PAIR(str[i]));
		wprintw(data->w_stats, "-");
		wattroff(data->w_stats, COLOR_PAIR(str[i]));
		i++;
	}
}

void	print_line(t_data_cor *data, int str[48], int *tirets, int *tot_tiret)
{
	int		i;
	int		lives[4];

	i = 0;
	while (i < data->nb_champs)
	{
		lives[i] = (data->all_the_champ[i].nbr_lives * 48) /
		((data->total_lives == 0) ? (1) : (data->total_lives));
		if (lives[i] != 0)
			wattron(data->w_stats, COLOR_PAIR(i + 1));
		while (*tirets != lives[i])
		{
			wprintw(data->w_stats, "-");
			str[*tot_tiret] = i + 1;
			*(tot_tiret) += 1;
			*(tirets) += 1;
		}
		if (lives[i] != 0)
			wattroff(data->w_stats, COLOR_PAIR(i + 1));
		*(tirets) = 0;
		i++;
	}
}

void	print_champ(t_data_cor *data, int line, int i)
{
	if (data->play_opt == 1)
		mvwprintw(data->w_stats, line, 1, "Player %d:",
		(data->all_the_champ[i].player_num + 1) + 0xffffffff + 1);
	else
		mvwprintw(data->w_stats, line, 1, "Player %d:",
		(data->all_the_champ[i].player_num + 1) + 0xffffffff + 1);
	wattron(data->w_stats, COLOR_PAIR(data->all_the_champ[i].order + 1));
	wprintw(data->w_stats, " %s", data->all_the_champ[i].header->prog_name);
	wattroff(data->w_stats, COLOR_PAIR(data->all_the_champ[i].order + 1));
	mvwprintw(data->w_stats, line + 1, 1,
	"	Lives in current period:		%d  ",
		data->all_the_champ[i].nbr_lives);
	mvwprintw(data->w_stats, line + 2, 1, "	Last live:				%d  ",
		data->all_the_champ[i].last_live);
}

void	set_color_printon(t_data_cor *data, int *color, int i)
{
	*color = wattron(data->w_arena, COLOR_PAIR(data->arena_color[i]));
	if (data->arena_bright[i] > 0)
		wattron(data->w_arena, A_BOLD);
	else if (data->arena_bright[i] < 0)
	{
		wattroff(data->w_arena, COLOR_PAIR(data->arena_color[i]));
		wattron(data->w_arena,
			COLOR_PAIR(((0 - data->arena_bright[i]) % data->nb_champs) + 14));
	}
}

void	print_arena(t_data_cor *data)
{
	int		i;
	int		color;

	color = 0;
	i = 0;
	wmove(data->w_arena, 1, 2);
	while (i < MEM_SIZE)
	{
		if (data->arena_color[i] != 0)
			set_color_printon(data, &color, i);
		wprintw(data->w_arena, "%02x", data->arena[i]);
		if (data->arena_color[i] != 0)
			set_color_printoff(data, &color, i);
		if ((i == 63) || ((i > 63) && ((i - 63) % 64 == 0)))
			pass_line(data);
		else
			wprintw(data->w_arena, " ");
		i++;
	}
}
