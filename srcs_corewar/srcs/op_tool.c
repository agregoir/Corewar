/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:30:29 by agregoir          #+#    #+#             */
/*   Updated: 2018/02/17 19:22:12 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			free_tab(int **tab)
{
	int		b;

	b = 0;
	while (b < 3)
	{
		free(tab[b]);
		b++;
	}
	free(tab);
}

unsigned int	get_playernum(t_data_cor *data, unsigned char *ptr,
	int iterations)
{
	int		pow;
	int		bitsnum;
	int		result;

	result = 0;
	bitsnum = iterations;
	pow = 1;
	while (bitsnum > 1)
	{
		pow *= 256;
		bitsnum--;
	}
	while (iterations > 0)
	{
		result += ((*ptr) * pow);
		pow /= 256;
		ptr += 1;
		if (ptr > data->arena + (MEM_SIZE - 1))
			ptr -= MEM_SIZE;
		iterations--;
	}
	return (result);
}

int				ft_swap_bit(int to_swap)
{
	int		swap_done;

	swap_done = 0;
	swap_done += (to_swap & 0x000000ff) << 24;
	swap_done += (to_swap & 0x0000ff00) << 8;
	swap_done += (to_swap & 0x00ff0000) >> 8;
	swap_done += (to_swap & 0xff000000) >> 24;
	return (swap_done);
}

void			copie_regs(t_proc *fiston, t_proc *papounet)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		fiston->regs[i] = papounet->regs[i];
		i++;
	}
}

void			copie_cette_merde(t_proc *fiston, t_proc *papounet)
{
	fiston->player_num = papounet->player_num;
	fiston->champ_name = papounet->champ_name;
	copie_regs(fiston, papounet);
	fiston->pc = papounet->pc;
	fiston->carry = papounet->carry;
	fiston->start_index = papounet->start_index;
	fiston->nbr_live = papounet->nbr_live;
	fiston->current_op = -1;
	fiston->current_exec_cycle = -1;
	fiston->color = papounet->color;
	fiston->color_index = papounet->color_index;
}
