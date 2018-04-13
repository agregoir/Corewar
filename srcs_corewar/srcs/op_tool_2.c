/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tool_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 14:24:35 by csimon            #+#    #+#             */
/*   Updated: 2018/03/17 14:24:37 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			ft_cpy(t_data_cor *data, unsigned int start, const void *value)
{
	size_t	index;
	char	*ptr_value;

	ptr_value = (char*)value;
	index = 0;
	while (index < 4)
	{
		if (start < MEM_SIZE)
			data->arena[start] = ptr_value[index];
		else
			data->arena[start % MEM_SIZE] = ptr_value[index];
		index++;
		start++;
	}
	return ;
}

unsigned int	fetch_value(t_data_cor *data, t_proc *tmp, int address)
{
	unsigned char	*ptr;
	unsigned int	result;
	int				iterations;
	int				pow;
	int				i;

	i = 0;
	ptr = &(data->arena[(tmp->start_index +
		(tmp->pc + (address % IDX_MOD))) % MEM_SIZE]);
	while (ptr < data->arena)
		ptr += MEM_SIZE;
	iterations = 5;
	result = 0;
	pow = 0x1000000;
	while (--iterations)
	{
		result += ((*ptr) * pow);
		pow /= 256;
		i++;
		ptr = &(data->arena[(tmp->start_index + ((tmp->pc +
			(address % IDX_MOD)) + i)) % MEM_SIZE]);
		while (ptr < data->arena)
			ptr += MEM_SIZE;
	}
	return (result);
}

unsigned int	fetch_l_value(t_data_cor *data, t_proc *tmp, int address)
{
	unsigned char	*ptr;
	unsigned int	result;
	int				iterations;
	int				pow;
	int				i;

	i = 0;
	ptr = &(data->arena[(tmp->start_index + tmp->pc + address) % MEM_SIZE]);
	while (ptr < data->arena)
		ptr += MEM_SIZE;
	iterations = 4;
	result = 0;
	pow = 0x1000000;
	while (iterations)
	{
		result += ((*ptr) * pow);
		pow /= 256;
		iterations--;
		i++;
		ptr = &(data->arena[(tmp->start_index + tmp->pc + address + i)
			% MEM_SIZE]);
		while (ptr < data->arena)
			ptr += MEM_SIZE;
	}
	return (result);
}

void			write_value(t_data_cor *data, t_proc *tmp,
	int address, unsigned int value)
{
	unsigned int	start_index;
	unsigned int	swap;
	int				i;

	i = 0;
	start_index = tmp->start_index;
	start_index += tmp->pc;
	start_index += ((address) % IDX_MOD);
	start_index %= MEM_SIZE;
	swap = ft_swap_bit(value);
	ft_cpy(data, start_index, &swap);
	if (data->is_visual == 1)
	{
		while (i < 4)
		{
			data->arena_color[(start_index + i) % MEM_SIZE] = tmp->color;
			data->arena_bright[(start_index + i) % MEM_SIZE] = 50;
			i++;
		}
	}
}

void			write_l_value(t_data_cor *data, t_proc *tmp,
	int address, unsigned int value)
{
	unsigned int	start_index;
	unsigned int	swap;
	int				i;

	i = 0;
	start_index = ((tmp->start_index + tmp->pc + address) % MEM_SIZE);
	swap = ft_swap_bit(value);
	ft_cpy(data, start_index, &swap);
	if (data->is_visual == 1)
	{
		while (i < 4)
		{
			data->arena_color[(start_index + i) % MEM_SIZE] = tmp->color;
			data->arena_bright[(start_index + i) % MEM_SIZE] = 50;
			i++;
		}
	}
}
