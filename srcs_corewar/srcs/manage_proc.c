/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 17:39:19 by agregoir          #+#    #+#             */
/*   Updated: 2018/02/15 17:40:13 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_nb_proc(t_proc *begin)
{
	int		i;

	i = 0;
	while (begin != NULL)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}

int		put_id(void)
{
	static int	id = 0;

	id++;
	return (id);
}

int		check_reg(unsigned char reg)
{
	if (reg < 1 || reg > 16)
		return (0);
	return (1);
}

t_proc	*add_proc(t_proc *new, t_proc **begin)
{
	t_proc *tmp;

	new->proc_id = put_id();
	if (*begin == NULL)
	{
		*begin = new;
		return (*begin);
	}
	tmp = *begin;
	*begin = new;
	new->next = tmp;
	return (*begin);
}

t_proc	**kill_proc(t_proc **begin, t_proc *tmp)
{
	t_proc *tmp2;

	tmp2 = *begin;
	if (tmp2 == tmp)
	{
		*begin = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	return (begin);
}
