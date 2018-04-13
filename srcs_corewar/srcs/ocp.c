/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:25:31 by csimon            #+#    #+#             */
/*   Updated: 2018/02/02 12:13:12 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_ocp(int **ocp_tab, t_arg_type params[3], int nb_param)
{
	int		i;

	i = 0;
	while (i < nb_param)
	{
		if (((char)ocp_tab[i][0] & params[i]) == 0)
			return (0);
		if (ocp_tab[i][0] == 1 && (ocp_tab[i][1] < 1 || ocp_tab[i][1] > 16))
			return (0);
		i++;
	}
	return (1);
}

int		**get_types(unsigned char ocp)
{
	int		**tab;
	int		b;

	b = 0;
	if ((tab = ft_memalloc(sizeof(int*) * 3)) == NULL)
		ft_error(ALLOC_FAILED);
	while (b < 3)
	{
		if ((tab[b] = ft_memalloc(sizeof(int) * 2)) == NULL)
			ft_error(ALLOC_FAILED);
		b++;
	}
	tab[0][0] = (ocp & 0b11000000) >> 6;
	tab[1][0] = (ocp & 0b00110000) >> 4;
	tab[2][0] = (ocp & 0b00001100) >> 2;
	b = 0;
	while (b < 3)
	{
		if (tab[b][0] == 3)
			tab[b][0] = 4;
		b++;
	}
	return (tab);
}

int		get_values(unsigned char *arena_start, unsigned char **pc,
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
		result += ((**(pc)) * pow);
		pow /= 256;
		*(pc) += 1;
		if (*(pc) > arena_start + (MEM_SIZE - 1))
			*(pc) -= MEM_SIZE;
		iterations--;
	}
	return (result);
}

int		**call_ocp(unsigned char *arena_start, unsigned char ocp,
	unsigned short *pc, int short_c)
{
	int				i;
	unsigned char	*pc2;
	int				**tab;

	pc2 = (unsigned char *)pc + 2;
	while (pc2 > arena_start + (MEM_SIZE - 1))
		pc2 -= MEM_SIZE;
	i = 0;
	tab = get_types(ocp);
	while (i < 3)
	{
		if (tab[i][0] == 1)
			tab[i][1] = get_values(arena_start, &pc2, 1);
		else if (tab[i][0] == 2)
		{
			if (short_c == 1)
				tab[i][1] = get_values(arena_start, &pc2, 2);
			else
				tab[i][1] = get_values(arena_start, &pc2, 4);
		}
		else if (tab[i][0] == 4)
			tab[i][1] = get_values(arena_start, &pc2, 2);
		i++;
	}
	return (tab);
}
