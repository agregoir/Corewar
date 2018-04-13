/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:11:07 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/04/07 17:03:22 by icampill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int argc, char **argv)
{
	t_line	*lines;
	t_file	*file;
	char	*s;

	if (argc != 2 || !((s = ft_strstr(argv[1], ".s")) && *(s + 2) == 0))
		ft_exit("Please gimme one valid .s file\n");
	file = make_file(argv[1]);
	lines = file->lines;
	file->tokens = tokenize(file);
	check_ins(file);
	check_param(file);
	file->ins = gen_ins(file);
	put_params(file);
	write_file(file, argv[1]);
	free_file(file);
	return (0);
}
