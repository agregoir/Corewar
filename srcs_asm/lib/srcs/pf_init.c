/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 08:16:31 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/17 22:17:25 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_pf	*pf_init(int fd, const char *format, va_list args)
{
	t_pf	*theman;

	if (!(theman = (t_pf *)malloc(sizeof(t_pf))))
		exit(0);
	theman->err = 0;
	theman->fd = fd;
	theman->pos = theman->buff;
	theman->job = parse(format, args);
	theman->format = (char *)format;
	theman->ret = 0;
	theman->left = BUFF_SIZE_PF;
	return (theman);
}
