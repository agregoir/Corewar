/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 18:58:54 by agregoir          #+#    #+#             */
/*   Updated: 2018/02/19 12:06:46 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_playnum(const char *str)
{
	int		i;
	int		nb;
	int		check;

	i = 0;
	nb = 0;
	check = 0;
	while ((str[i] == '\t') || (str[i] == '\v') || (str[i] == '\r') ||
			(str[i] == '\f') || (str[i] == '\n') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
		if (((str[i] < '0') || (str[i] > '9')) && str[i] != '\0')
			return (-1);
		check = 1;
	}
	if ((nb < 0) || (check == 0))
		return (-1);
	if (nb > PLAYER_NUM_MAX)
		ft_error(PLAYER_NUM_MAX);
	return (nb);
}

void	check_num(t_data_cor *data, char **argv, int *i, int champ_i)
{
	data->play_opt = 1;
	(*i)++;
	if ((data->all_the_champ[champ_i].player_num = get_playnum(argv[*i])) == -1)
		ft_error(ERROR_NO_PLAYNUM);
	(*i)++;
	acquire_champ(argv[*i], data, champ_i);
}

void	check_args(int argc, char **argv, t_data_cor *data)
{
	static int		argv_index = 1;
	static int		champ_i = 0;
	static int		champnum = 0;

	data->all_the_champ = init_tab_champ();
	if (is_dump_opt(argv[argv_index]) == TRUE && argv_index++)
		data->dump_cycles = ft_atoi(argv[argv_index++]);
	while (argv_index < argc)
	{
		if (is_visualize_opt(data, argv[argv_index]) == TRUE)
		{
			if (argv_index >= argc - 1)
				break ;
			argv_index++;
		}
		if (is_playnum_opt(argv[argv_index]) == TRUE && argv_index < argc - 1)
			check_num(data, argv, &argv_index, champ_i);
		else if (champnum < MAX_PLAYERS)
		{
			acquire_champ(argv[argv_index++], data, champ_i);
			champ_i++;
			champnum++;
		}
	}
	pre_loading(data->all_the_champ, champnum, data);
}
