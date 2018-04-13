/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 10:02:01 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/18 00:27:40 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*flush_buff(t_pf *pf)
{
	size_t	len;
	ssize_t	r;

	len = pf->pos - pf->buff;
	r = write(pf->fd, pf->buff, len);
	if (r < 0)
		pf->err = 1;
	ft_bzero(pf->buff, BUFF_SIZE_PF);
	pf->pos = pf->buff;
	pf->left = BUFF_SIZE_PF;
	return (pf->pos);
}

void	update_nums(t_pf *pf, size_t len)
{
	pf->pos += len;
	pf->left -= len;
	pf->ret += len;
}

void	pf_putc(t_pf *pf, char c, size_t n)
{
	char	*pos;

	while (n-- > 0)
	{
		pos = pf->left == 0 ? flush_buff(pf) : pf->pos;
		*pos = c;
		pf->pos++;
		pf->left--;
		pf->ret++;
	}
}

void	pf_puts(t_pf *pf, char *s, ssize_t n)
{
	char	*pos;

	while (n != 0 && s && *s)
	{
		pos = pf->left == 0 ? flush_buff(pf) : pf->pos;
		*pos = *s;
		s++;
		pf->pos++;
		pf->left--;
		pf->ret++;
		n--;
	}
}
