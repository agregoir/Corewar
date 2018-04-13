/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:16:20 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/18 00:28:33 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			pf_di(t_pf *pf, va_list args)
{
	intmax_t	num;
	size_t		digs;

	if (pf->job->type == 'D')
		pf->job->len = 'l';
	num = pf_fetch_d(pf, args);
	digs = pf_nb_size(ABS(num), 10);
	digs = num == 0 && pf->job->prec == 0 ? 0 : digs;
	handle_pdd(pf, num < 0, digs);
	pf_putint(pf, num, "0123456789");
	handle_pdmd(pf, num < 0, digs);
}

void			pf_u(t_pf *pf, va_list args)
{
	uintmax_t	num;
	size_t		digs;

	if (pf->job->type == 'U')
		pf->job->len = 'l';
	num = pf_fetch_u(pf, args);
	digs = pf_nb_size(num, 10);
	digs = num == 0 && pf->job->prec == 0 ? 0 : digs;
	handle_pdd(pf, 0, digs);
	pf_putuint(pf, num, "0123456789");
	handle_pdmd(pf, 0, digs);
}

void			pf_x(t_pf *pf, va_list args)
{
	uintmax_t	num;
	size_t		digs;

	num = pf_fetch_u(pf, args);
	digs = pf_nb_size(num, 16);
	digs = num == 0 && pf->job->prec == 0 ? 0 : digs;
	handle_pdd(pf, 0, digs);
	if (pf->job->flags % 11 == 0 && num > 0)
	{
		pf_puts(pf, pf->job->type == 'x' ? "0x" : "0X", 2);
		pf->job->minw -= pf->job->minw >= 2 ? 2 : 0;
	}
	pf_putuint(pf, num, pf->job->type == 'x' ? B16 : B16M);
	handle_pdmd(pf, 0, digs);
}

void			pf_o(t_pf *pf, va_list args)
{
	uintmax_t	num;
	size_t		digs;

	if (pf->job->type == 'O')
		pf->job->len = 'l';
	num = pf_fetch_u(pf, args);
	digs = pf_nb_size(num, 8);
	digs = num == 0 && pf->job->prec == 0 ? 0 : digs;
	if (pf->job->flags % 11 == 0 && (ssize_t)digs >= pf->job->prec)
		pf->job->prec = num == 0 && pf->job->prec == -1 ? 1 : digs + 1;
	handle_pdd(pf, 0, digs);
	pf_putuint(pf, num, "01234567");
	handle_pdmd(pf, 0, digs);
}

void			pf_p(t_pf *pf, va_list args)
{
	uintmax_t	num;
	size_t		digs;

	if (pf->job->type == 'X')
		pf->job->len = 'l';
	num = (uintmax_t)va_arg(args, void *);
	digs = pf_nb_size(num, 16);
	handle_pdd(pf, 0, digs + 2);
	pf_puts(pf, "0x", 2);
	pf_putuint(pf, num, B16);
	handle_pdmd(pf, 0, digs + 2);
}
