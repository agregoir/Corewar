/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curses_visu_breakdown.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:07:57 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:07:59 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <ncurses.h>

void	lives_breakdown_last(t_data_cor *data, int str[48], int *line)
{
	static int	first_call = 0;
	int			i;

	i = 0;
	mvwprintw(data->w_stats, *line, 1, "Live breakdown for last period:");
	*line += 1;
	wattron(data->w_stats, COLOR_PAIR(13));
	mvwprintw(data->w_stats, *line, 1, "[");
	if (first_call == 0)
		while (i < 48 && i++)
			wprintw(data->w_stats, "-");
	wattroff(data->w_stats, COLOR_PAIR(13));
	if (data->cycles_to_die != 0 && (data->current_cycle %
		data->cycles_to_die) == 0)
	{
		print_line_last(data, str, i);
		first_call = 1;
	}
	wattron(data->w_stats, COLOR_PAIR(13));
	if (data->cycles_to_die != 0 && ((data->current_cycle %
		data->cycles_to_die) == 0 || first_call == 0))
		wprintw(data->w_stats, "]");
	wattroff(data->w_stats, COLOR_PAIR(13));
	*line += 2;
}

void	lives_breakdown(t_data_cor *data, int *line)
{
	int			tirets;
	int			tot_tirets;
	static int	str[48];

	tot_tirets = 0;
	tirets = 0;
	*line += 1;
	mvwprintw(data->w_stats, *line, 1, "Live breakdown for current period:");
	wattron(data->w_stats, COLOR_PAIR(13));
	*line += 1;
	mvwprintw(data->w_stats, *line, 1, "[");
	print_line(data, str, &tirets, &tot_tirets);
	wattron(data->w_stats, COLOR_PAIR(13));
	while (tot_tirets != 48)
	{
		wprintw(data->w_stats, "-");
		if (data->cycles_to_die > 50)
			str[tot_tirets] = 13;
		tot_tirets++;
	}
	wprintw(data->w_stats, "]");
	wattroff(data->w_stats, COLOR_PAIR(13));
	*line += 2;
	lives_breakdown_last(data, str, line);
}

int		get_next(t_data_cor *data, int i)
{
	int		next;

	next = 0;
	while (data->all_the_champ[next].order != i)
		next++;
	return (next);
}

void	pass_line(t_data_cor *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	getyx(data->w_arena, y, x);
	wprintw(data->w_arena, "\n");
	wmove(data->w_arena, y + 1, 2);
}

void	set_color_printoff(t_data_cor *data, int *color, int i)
{
	if (*color != 1)
	{
		wattroff(data->w_arena, COLOR_PAIR(data->arena_color[i]));
		if (data->arena_bright[i] > 0)
		{
			wattroff(data->w_arena, A_BOLD);
			data->arena_bright[i] -= 1;
		}
		else if (data->arena_bright[i] < 0)
		{
			wattroff(data->w_arena,
			COLOR_PAIR(((0 - data->arena_bright[i]) % data->nb_champs) + 14));
			data->arena_bright[i] += data->nb_champs;
			if (data->arena_bright[i] > -4)
				data->arena_bright[i] = 0;
		}
		*color = 1;
	}
}
