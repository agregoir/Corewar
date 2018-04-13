/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 10:22:18 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/18 00:29:05 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "printf.h"

void		handle_pds(t_pf *pf, size_t len)
{
	t_ui	space;
	t_ui	min;

	min = (t_ui)pf->job->minw;
	if (min && pf->job->flags % 2 && pf->job->flags % 7)
	{
		space = len < min ? min - len : 0;
		pf_putc(pf, ' ', space);
	}
}

void		handle_pdms(t_pf *pf, size_t len)
{
	t_ui	space;
	t_ui	min;

	min = (t_ui)pf->job->minw;
	if (min && (pf->job->flags % 2 == 0))
	{
		space = len < min ? min - len : 0;
		pf_putc(pf, ' ', space);
	}
}

void		pf_pct(t_pf *pf, va_list args)
{
	(void)args;
	handle_pds(pf, 1);
	if (pf->job->flags % 7 == 0 && pf->job->minw > 0)
		pf_putc(pf, '0', pf->job->minw - 1);
	pf_putc(pf, '%', 1);
	handle_pdms(pf, 1);
}
