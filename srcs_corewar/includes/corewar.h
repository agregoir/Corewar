/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:43:18 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:43:20 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define PLAYER_NUM_MAX 1000
# define ERROR_NO_ARG 1
# define ERROR_OPEN_CHAMP 2
# define ERROR_TOO_MANY_CHAMPS 3
# define ERROR_NO_PLAYNUM 4
# define ERROR_INVALID_CHAMPION 5
# define ERROR_SIZE_CHAMP 6
# define ALLOC_FAILED 7
# define HEADER_SIZE 2195
# define C ft_printf("\033[H\033[2J");
# include <fcntl.h>
# include <ncurses.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"
# include "libft.h"
# include "op.h"

typedef struct	s_proc
{
	int				player_num;
	int				proc_id;
	char			*champ_name;
	int				regs[REG_NUMBER];
	unsigned short	pc;
	int				carry;
	int				start_index;
	int				color_index;
	int				nbr_live;
	int				current_op;
	int				current_exec_cycle;
	unsigned char	*pc_index;
	int				color;
	struct s_proc	*next;
}				t_proc;

typedef struct	s_champion
{
	int				order;
	int				player_num;
	t_header		*header;
	int				nbr_lives;
	int				last_live;
	int				prog_size;
	int				fd;
	unsigned char	code_part[(MEM_SIZE / 6)];
}				t_champion;

typedef struct	s_data_cor
{
	int				dump_cycles;
	unsigned char	*arena;
	unsigned char	*arena_color;
	char			*arena_bright;
	int				current_cycle;
	int				cycles_to_die;
	t_proc			*proc_begin;
	int				player_num;
	int				total_lives;
	int				total_lives_all;
	int				play_opt;
	int				is_visual;
	int				champ_lives[4];
	int				champ_color[4];
	unsigned int	last_champ_alive;
	int				period_elapsed;
	int				nb_champs;
	int				max_checks;
	t_champion		*all_the_champ;
	WINDOW			*w_arena;
	WINDOW			*w_stats;
}				t_data_cor;

/*
** acquire_champ.c
*/
unsigned int	get_champ_magic(unsigned char *header);
unsigned int	get_champ_len(unsigned char *header);
void			init_champ_header(t_header *header, unsigned char *buffer);
int				acquire_champ(char *name, t_data_cor *data, int i);

/*
** curses_visu.c
*/
void			spectate_battle(t_data_cor *data, int code);

/*
** Curses_visu_breakdown.c
*/
void			lives_breakdown_last(t_data_cor *data, int str[48], int *line);
void			lives_breakdown(t_data_cor *data, int *line);
void			pass_line(t_data_cor *data);
void			set_color_printoff(t_data_cor *data, int *color, int i);
int				get_next(t_data_cor *data, int i);

/*
** Curses_visu_print.c
*/
void			print_line_last(t_data_cor *data, int str[48], int i);
void			print_line(t_data_cor *data, int str[48], int *tirets,
	int *tot_tiret);
void			print_champ(t_data_cor *data, int line, int i);
void			print_arena(t_data_cor *data);

/*
** init.c
*/
t_proc			*init_proc(t_champion *champ, int start_index);
t_champion		*init_tab_champ(void);
t_data_cor		*init_data(void);
void			cast_curses(t_data_cor *data);

/*
** load.c
*/
void			load_champ(t_data_cor *data, int champnum,
	t_champion *champ);
int				which_next(t_champion champ[4], int champnum);
int				find_next_free(t_champion champs[4], int to_change);
void			solve_double(t_champion chp[4]);
void			pre_loading(t_champion *all_the_champ, int champnum,
	t_data_cor *data);

/*
** main.c
*/
void			dump_stuff(t_data_cor *data);
int				ft_error(int code);

/*
** manage_op.c
*/
void			get_op(t_proc *tmp, unsigned char *str);
void			execute_op(t_data_cor *data, t_proc *tmp, unsigned char *str);
void			check_op(t_data_cor *data, t_proc *tmp);
int				check_reg(unsigned char reg);

/*
** manage_proc.c
*/
int				get_nb_proc(t_proc *begin);
t_proc			*add_proc(t_proc *new, t_proc **begin);
t_proc			**kill_proc(t_proc **begin, t_proc *tmp);

/*
** ocp.c
*/
int				check_ocp(int **ocp_tab, t_arg_type params[3],
	int nb_param);
int				**get_types(unsigned char ocp);
int				get_values(unsigned char *arena_start, unsigned char **pc,
	int iterations);
int				**call_ocp(unsigned char *arena_start, unsigned char ocp,
	unsigned short *pc, int short_c);

/*
** op_1.c
*/
void			live_op(t_data_cor *data, t_proc *tmp);
void			ft_ld(t_data_cor *data, t_proc *tmp);
void			ft_st(t_data_cor *data, t_proc *tmp);
void			ft_add(t_data_cor *data, t_proc *tmp);

/*
** op_2.c
*/
void			ft_sub(t_data_cor *data, t_proc *tmp);
void			ft_and(t_data_cor *data, t_proc *tmp);
void			ft_or(t_data_cor *data, t_proc *tmp);
void			ft_xor(t_data_cor *data, t_proc *tmp);

/*
** op_3.c
*/
void			ft_zjmp(t_data_cor *data, t_proc *tmp);
void			ft_ldi(t_data_cor *data, t_proc *tmp);
void			ft_sti(t_data_cor *data, t_proc *tmp);
void			ft_fork(t_data_cor *data, t_proc *tmp);

/*
** op_4.c
*/
void			ft_lld(t_data_cor *data, t_proc *tmp);
void			ft_lldi(t_data_cor *data, t_proc *tmp);
void			ft_lfork(t_data_cor *data, t_proc *tmp);
void			ft_aff(t_data_cor *data, t_proc *tmp);

/*
** op_tool.c
*/
void			free_tab(int **tab);
unsigned int	get_playernum(t_data_cor *data, unsigned char *ptr,
	int iterations);
int				ft_swap_bit(int to_swap);
void			copie_cette_merde(t_proc *fiston, t_proc *papounet);

/*
** op_tool_2.c
*/
void			ft_cpy(t_data_cor *data, unsigned int start, const void *value);
unsigned int	fetch_value(t_data_cor *data, t_proc *tmp, int address);
unsigned int	fetch_l_value(t_data_cor *data, t_proc *tmp, int address);
void			write_value(t_data_cor *data, t_proc *tmp,
	int address, unsigned int value);
void			write_l_value(t_data_cor *data, t_proc *tmp,
	int address, unsigned int value);

/*
** parse.c
*/
int				get_playnum(const char *str);
void			check_num(t_data_cor *data, char **argv, int *i, int champ_i);
void			check_args(int argc, char **argv, t_data_cor *data);

/*
** tool.c
*/
int				is_dump_opt(char *str);
int				is_visualize_opt(t_data_cor *data, char *str);
int				is_playnum_opt(char *str);
void			deal_data_lives(t_data_cor *data);
int				end_op(t_proc *tmp, int **ocp_tab, int short_dir,
	int nb_param);

/*
** wage_war.c
*/
void			start_war(t_data_cor *data);

typedef struct	s_op
{
	char				*label;
	unsigned int		num_params;
	t_arg_type			params[3];
	unsigned int		op_code;
	unsigned int		cycles;
	char				*desc;
	unsigned int		coding_param;
	unsigned int		short_dir;
}				t_op;

static t_op		g_op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

typedef struct	s_op_fct
{
	void			(*ptr)(t_data_cor *data, t_proc *tmp);
	unsigned int	op_code;
	unsigned int	add_restrict;
	unsigned int	modif_carry;
}				t_op_fct;

static		t_op_fct g_fct_tab[17] =
{
	{&live_op, 1, 1, 0},
	{&ft_ld, 2, 1, 1},
	{&ft_st, 3, 1, 0},
	{&ft_add, 4, 1, 1},
	{&ft_sub, 5, 1, 1},
	{&ft_and, 6, 1, 1},
	{&ft_or, 7, 1, 1},
	{&ft_xor, 8, 1, 1},
	{&ft_zjmp, 9, 1, 0},
	{&ft_ldi, 10, 1, 0},
	{&ft_sti, 11, 1, 0},
	{&ft_fork, 12, 1, 0},
	{&ft_lld, 13, 0, 1},
	{&ft_lldi, 14, 0, 1},
	{&ft_lfork, 15, 0, 0},
	{&ft_aff, 16, 1, 0},
	{0, 0, 0, 0}
};

#endif
