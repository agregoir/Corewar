/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:38:47 by agregoir          #+#    #+#             */
/*   Updated: 2018/02/15 17:40:37 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_proc		*init_proc(t_champion *champ, int start_index)
{
	t_proc		*new;
	static int	color = 1;

	if ((new = (t_proc *)ft_memalloc(sizeof(t_proc))) == NULL)
		ft_error(ALLOC_FAILED);
	new->player_num = 0xffffffff - champ->player_num;
	new->proc_id = 0;
	new->champ_name = champ->header->prog_name;
	ft_memset(new->regs, 0, 64);
	ft_memcpy(new->regs, &new->player_num, 4);
	new->pc = 0;
	new->carry = 0;
	new->start_index = start_index;
	new->nbr_live = 0;
	new->current_op = -1;
	new->current_exec_cycle = 0;
	new->next = NULL;
	new->color = color;
	color += 1;
	return (new);
}

t_champion	*init_tab_champ(void)
{
	int			i;
	t_champion	*all_the_champ;

	if ((all_the_champ = (t_champion *)ft_memalloc(sizeof(t_champion) * 4))
	== NULL)
		ft_error(ALLOC_FAILED);
	i = 0;
	while (i < 4)
	{
		all_the_champ[i].player_num = -1;
		if ((all_the_champ[i].header =
		(t_header *)ft_memalloc(sizeof(t_header))) == NULL)
			ft_error(ALLOC_FAILED);
		all_the_champ[i].nbr_lives = 0;
		all_the_champ[i].order = 0;
		ft_bzero(all_the_champ[i].code_part, 682);
		i++;
	}
	return (all_the_champ);
}

t_data_cor	*init_data(void)
{
	t_data_cor	*data;

	if ((data = (t_data_cor*)ft_memalloc(sizeof(t_data_cor))) == NULL
	|| (data->arena = (unsigned char*)ft_memalloc(MEM_SIZE + 1)) == NULL
	|| (data->arena_color = (unsigned char*)ft_memalloc(MEM_SIZE + 1)) == NULL
	|| (data->arena_bright = (char*)ft_memalloc(MEM_SIZE + 1)) == NULL)
		ft_error(ALLOC_FAILED);
	data->dump_cycles = -1;
	data->cycles_to_die = CYCLE_TO_DIE;
	data->total_lives = 0;
	data->total_lives_all = 0;
	data->champ_lives[0] = -1;
	data->champ_lives[1] = -1;
	data->champ_lives[2] = -1;
	data->champ_lives[3] = -1;
	data->is_visual = 0;
	data->play_opt = 0;
	data->period_elapsed = 0;
	data->last_champ_alive = -8;
	data->w_arena = NULL;
	data->w_stats = NULL;
	data->nb_champs = 0;
	data->max_checks = MAX_CHECKS;
	return (data);
}

void		init_colors(void)
{
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(6, COLOR_BLUE, COLOR_MAGENTA);
	init_pair(7, COLOR_GREEN, COLOR_MAGENTA);
	init_pair(8, COLOR_RED, COLOR_MAGENTA);
	init_pair(9, COLOR_YELLOW, COLOR_MAGENTA);
	init_pair(10, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(11, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(12, COLOR_WHITE, COLOR_BLACK);
	init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(14, COLOR_WHITE, COLOR_BLUE);
	init_pair(15, COLOR_WHITE, COLOR_GREEN);
	init_pair(16, COLOR_WHITE, COLOR_RED);
	init_pair(17, COLOR_WHITE, COLOR_YELLOW);
}

void		cast_curses(t_data_cor *data)
{
	initscr();
	noecho();
	cbreak();
	start_color();
	init_color(COLOR_MAGENTA, 400, 400, 400);
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_colors();
	bkgd(COLOR_PAIR(11));
	data->w_arena = newwin(66, 195, 1, 1);
	data->w_stats = newwin(66, 55, 1, 197);
	wbkgd(data->w_arena, COLOR_PAIR(13));
	wbkgd(data->w_stats, COLOR_PAIR(12));
	nodelay(data->w_arena, 1);
	keypad(data->w_arena, TRUE);
	refresh();
	wrefresh(data->w_arena);
	wrefresh(data->w_stats);
}
