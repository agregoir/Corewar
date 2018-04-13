/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acquire_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:16:56 by agregoir          #+#    #+#             */
/*   Updated: 2018/01/19 11:21:48 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	get_champ_magic(unsigned char *header)
{
	if (header[0] == 0x00 && header[1] == 0xea && header[2] == 0x83
		&& header[3] == 0xf3)
		return (0xea83f3);
	else
		return (ERROR);
}

unsigned int	get_champ_len(unsigned char *header)
{
	unsigned int	len;
	unsigned char	*to_convert;

	len = 0x0;
	if ((to_convert = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 2))
		== NULL)
		ft_error(ALLOC_FAILED);
	to_convert[0] = header[138];
	to_convert[1] = header[139];
	len = (to_convert[0] * 256) + (to_convert[1]);
	free(to_convert);
	return (len);
}

void			init_champ_header(t_header *header, unsigned char *buffer)
{
	int		index_header;
	int		index;

	index_header = 140;
	index = 0;
	while (index < 2052)
	{
		header->comment[index] = buffer[index_header + index];
		index++;
	}
	index_header = 4;
	index = 0;
	while (index < 132)
	{
		header->prog_name[index] = buffer[index_header + index];
		index++;
	}
	header->magic = get_champ_magic(buffer);
	header->prog_size = get_champ_len(buffer);
	return ;
}

int				acquire_champ(char *name, t_data_cor *data, int i)
{
	int				fd;
	unsigned char	*header;
	char			*test;

	test = NULL;
	if ((header = (unsigned char *)ft_memalloc(HEADER_SIZE)) == NULL)
		ft_error(ALLOC_FAILED);
	if ((fd = open(name, O_RDONLY)) == ERROR || i > 4)
		ft_error(ERROR_OPEN_CHAMP);
	read(fd, header, 2192);
	init_champ_header(data->all_the_champ[i].header, header);
	if (data->all_the_champ[i].header->magic != COREWAR_EXEC_MAGIC ||
		data->all_the_champ[i].header->prog_size > CHAMP_MAX_SIZE)
	{
		ft_printf("Champ_size = %d\n",
			data->all_the_champ[i].header->prog_size);
		ft_error(ERROR_INVALID_CHAMPION);
	}
	data->all_the_champ[i].fd = fd;
	data->all_the_champ[i].prog_size = data->all_the_champ[i].header->prog_size;
	read(fd, data->all_the_champ[i].code_part,
		data->all_the_champ[i].header->prog_size);
	(read(fd, test, 1) > 0) ? (ft_error(ERROR_SIZE_CHAMP)) : 0;
	free(header);
	return (0);
}
