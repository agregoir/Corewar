/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 09:43:12 by csimon            #+#    #+#             */
/*   Updated: 2018/03/12 09:43:14 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dump_stuff(t_data_cor *data)
{
	int		i;

	i = 0;
	while (i < 4096)
	{
		if (i == 0 || i % 64 == 0)
			ft_printf("0x%04x : %02x", i, data->arena[i]);
		else
			ft_printf("%02x", data->arena[i]);
		if ((i == 63) || ((i > 63) && ((i - 63) % 64 == 0)))
			ft_printf(" \n");
		else
			ft_printf(" ");
		i++;
	}
	exit(1);
}

int		ft_error(int code)
{
	char	*str;

	if (code == ERROR_NO_ARG)
		str = "\n\nUsage: ./corewar  [-dump nbr_cycles] \
[[-n [num]] champion1.cor] ... [-ncurses]";
	else if (code == ERROR_OPEN_CHAMP)
		str = "Could not open champion";
	else if (code == ERROR_TOO_MANY_CHAMPS)
		str = "Too many champions";
	else if (code == ERROR_NO_PLAYNUM)
		str = "Invalid champion num specified after -n option";
	else if (code == ERROR_INVALID_CHAMPION)
		str = "Invalid champion header and/or size";
	else if (code == ERROR_SIZE_CHAMP)
		str = "Size in header and real size are not equal";
	else if (code == PLAYER_NUM_MAX)
		str = "Wrong player num";
	else if (code == ALLOC_FAILED)
		str = "Could not allocate memory";
	else
		str = "unidentified input error";
	ft_printf("An error occured: %s\n\nCorewar terminating\n", str);
	exit(0);
}

void	clean_blood(t_data_cor *data, int code)
{
	int		i;
	t_proc	*tmp;
	t_proc	*swp;

	i = 0;
	code = 0;
	tmp = data->proc_begin;
	while (i < 4)
	{
		free(data->all_the_champ[i].header);
		data->all_the_champ[i].header = NULL;
		i++;
	}
	if (data->proc_begin != NULL)
		while (tmp != NULL)
		{
			swp = tmp->next;
			free(tmp);
			tmp = swp;
		}
	free(data->arena_bright);
	free(data->arena_color);
	free(data->arena);
	free(data->all_the_champ);
	free(data);
}

int		main(int argc, char **argv)
{
	t_data_cor	*data;

	data = init_data();
	if (argc == 1)
		ft_error(ERROR_NO_ARG);
	check_args(argc, argv, data);
	if (data->is_visual == 1)
		cast_curses(data);
	start_war(data);
	endwin();
	clean_blood(data, 5);
	return (0);
}
