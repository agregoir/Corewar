/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:41:56 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:41:58 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_dump_opt(char *str)
{
	if (ft_strcmp(str, "-dump") == 0)
		return (TRUE);
	return (FALSE);
}

int		is_visualize_opt(t_data_cor *data, char *str)
{
	if (ft_strcmp(str, "-ncurses") == 0)
	{
		data->is_visual = 1;
		return (TRUE);
	}
	return (FALSE);
}

int		is_playnum_opt(char *str)
{
	if (ft_strcmp(str, "-n") == 0)
		return (TRUE);
	return (FALSE);
}

void	deal_data_lives(t_data_cor *data)
{
	int		i;

	i = 0;
	data->total_lives = 0;
	while (i < data->nb_champs)
	{
		data->all_the_champ[i].nbr_lives = 0;
		i++;
	}
}

int		end_op(t_proc *tmp, int **ocp_tab, int short_dir, int nb_param)
{
	int		len;
	int		i;

	i = 0;
	len = 2;
	while (i < nb_param)
	{
		if (ocp_tab[i][0] == 1)
			len += 1;
		if (ocp_tab[i][0] == 2)
		{
			if (short_dir)
				len += 2;
			else
				len += 4;
		}
		if (ocp_tab[i][0] == 4)
			len += 2;
		i++;
	}
	tmp->current_op = -1;
	free_tab(ocp_tab);
	return (len);
}
