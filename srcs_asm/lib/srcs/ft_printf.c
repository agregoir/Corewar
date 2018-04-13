/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:20:28 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/18 00:20:36 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			done;

	va_start(arg, format);
	done = ft_vfprintf(1, format, arg);
	va_end(arg);
	return (done);
}

int		ft_vfprintf(int fd, const char *format, va_list arg)
{
	t_pf	*pf;
	t_job	*head;
	int		r;

	pf = pf_init(fd, format, arg);
	head = pf->job;
	r = do_jobs(pf, arg);
	clean_up(pf, head);
	return (r);
}
