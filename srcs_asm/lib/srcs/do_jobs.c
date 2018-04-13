/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_jobs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:18:54 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/18 00:22:51 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** handle no jobs else where, ideally right after the parsing is done
** no jobs, print the format return the len and be done with it
*/

static void		handle_big(t_pf *pf, char *s, size_t len)
{
	ssize_t		r;

	if (pf->left != BUFF_SIZE_PF)
		flush_buff(pf);
	r = write(pf->fd, s, len);
	if (r < 0)
		pf->err = 1;
	pf->ret += (size_t)r;
}

static char		*handle_it(t_pf *pf)
{
	char	*s;
	char	*f;
	size_t	len;

	if (pf->job->prev)
		s = pf->job->prev->end;
	else
		s = pf->format;
	f = pf->job->start;
	len = f - s;
	append_s(pf, s, len);
	return (pf->job->next ? NULL : pf->job->end);
}

void			append_s(t_pf *pf, char *s, size_t len)
{
	if (len > BUFF_SIZE_PF)
		handle_big(pf, s, len);
	else
	{
		if (len > pf->left)
			flush_buff(pf);
		ft_memcpy(pf->pos, s, len);
		update_nums(pf, len);
	}
}

int				do_jobs(t_pf *pf, va_list args)
{
	int		i;
	char	*end;

	if (!(pf->job))
		handle_big(pf, pf->format, ft_strlen(pf->format));
	while (pf->job)
	{
		i = 0;
		end = handle_it(pf);
		while (g_ops[i].type != -1)
		{
			if (g_ops[i].type == pf->job->type)
			{
				g_ops[i].p(pf, args);
				break ;
			}
			++i;
		}
		pf->job = pf->job->next;
		if (end)
			append_s(pf, end, ft_strlen(end));
	}
	flush_buff(pf);
	return (pf->err ? -1 : pf->ret);
}
