/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:35:13 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/18 00:29:19 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		handle_pdd(t_pf *pf, int num, size_t len)
{
	t_ui	space;
	t_ui	min;
	size_t	lin;

	space = 0;
	lin = MAX(len, pf->job->prec > 0 ? (size_t)pf->job->prec : 0);
	lin += num || ((pf->job->type == 'd' || pf->job->type == 'D' ||
	pf->job->type == 'i') && pf->job->flags % 3 == 0);
	if (pf->job->type == 'x' || pf->job->type == 'x')
		lin += pf->job->flags % 11 == 0 ? 2 : 0;
	min = (t_ui)pf->job->minw;
	if (min && pf->job->flags % 2 && (pf->job->flags % 7 ||
	pf->job->prec >= 0))
	{
		space = lin < min ? min - lin : 0;
		pf_putc(pf, ' ', space);
	}
	if (pf->job->flags % 5 == 0 && space == 0 && pf->job->flags % 3 && !num
	&& (pf->job->type == 'd' || pf->job->type == 'D' ||
	pf->job->type == 'i'))
	{
		pf_putc(pf, ' ', 1);
		pf->job->minw -= (pf->job->flags % 7) ? 0 : 1;
	}
}

void		handle_pdmd(t_pf *pf, int num, size_t len)
{
	t_ui	space;
	t_ui	min;
	size_t	lin;

	lin = MAX(len, pf->job->prec > 0 ? (size_t)pf->job->prec : 0);
	lin += num || ((pf->job->type == 'd' || pf->job->type == 'D') &&
	pf->job->flags % 3 == 0);
	min = (t_ui)pf->job->minw;
	if (min && pf->job->flags % 2 == 0)
	{
		space = lin < min ? min - lin : 0;
		if (pf->job->flags % 5 == 0 && pf->job->flags % 3 && !num
		&& (pf->job->type == 'd' || pf->job->type == 'D'))
			space--;
		pf_putc(pf, ' ', space);
	}
}

void		clean_up(t_pf *pf, t_job *head)
{
	t_job	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	free(pf);
}
