/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:52:38 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/04/07 16:38:56 by icampill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int						rev_end(int value, int size)
{
	if (size == 1)
		return (value);
	else if (size == 2)
		return (value >> 8 | value << 8);
	else if (size == 4)
		return (((value >> 24) & 0xff) |
					((value << 8) & 0xff0000) |
					((value >> 8) & 0xff00) |
					((value << 24) & 0xff000000));
	else
		return (0);
}

void					write_ins(int fd, t_ins *ins)
{
	int		p;

	write(fd, &(ins->op->op_code), 1);
	if (ins->op->coding_param)
		write(fd, &(ins->ocp), 1);
	p = rev_end(ins->params[0], ins->para_size[0]);
	write(fd, &p, ins->para_size[0]);
	p = rev_end(ins->params[1], ins->para_size[1]);
	write(fd, &p, ins->para_size[1]);
	p = rev_end(ins->params[2], ins->para_size[2]);
	write(fd, &p, ins->para_size[2]);
}

static unsigned int		get_size(t_ins *ins)
{
	unsigned int	ret;

	ret = 0;
	while (ins)
	{
		ret += ins->size;
		ins = ins->next;
	}
	return (ret);
}

void					write_file(t_file *file, char *name)
{
	char	*n;
	int		fd;
	t_ins	*ins;

	ins = file->ins;
	n = (char *)ft_malloc((ft_strlen(name) + 3) * sizeof(char));
	ft_strncpy(n, name, ft_strlen(name) - 1);
	ft_strcat(n, "cor");
	fd = open(n, O_WRONLY | O_CREAT, 0777);
	file->header.prog_size = rev_end(get_size(file->ins), 4);
	ft_printf("Thank you for trusting me with your compilation\n");
	ft_printf("Good luck with the fight\n");
	write(fd, &(file->header), sizeof(t_header));
	while (ins)
	{
		write_ins(fd, ins);
		ins = ins->next;
	}
	free(n);
	close(fd);
}
