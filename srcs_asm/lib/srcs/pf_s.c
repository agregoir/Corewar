/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:06:28 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/17 23:40:48 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			pf_s(t_pf *pf, va_list args)
{
	size_t	len;
	char	*str;

	if (pf->job->len == 'l')
	{
		pf_ws(pf, args);
		return ;
	}
	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	len = pf->job->prec >= 0 ? MIN(pf->job->prec, (ssize_t)len) : len;
	handle_pds(pf, len);
	pf_puts(pf, str, len);
	handle_pdms(pf, len);
}

static size_t	handle_prec(t_pf *pf, wchar_t *s, size_t len)
{
	ssize_t	prec;
	size_t	preci;
	size_t	l;

	prec = pf->job->prec;
	l = 0;
	if (prec < 0 || (preci = (size_t)prec) >= len)
		return (len);
	while (*s && (l + pf_wclen(*s)) <= preci)
	{
		l += pf_wclen(*s);
		s++;
	}
	return (l);
}

void			pf_ws(t_pf *pf, va_list args)
{
	size_t	len;
	wchar_t	*str;

	str = va_arg(args, wchar_t *);
	if (str == NULL)
		str = L"(null)";
	len = pf_wcslen(str);
	len = handle_prec(pf, str, len);
	handle_pds(pf, len);
	pf_putws(pf, str, len);
	handle_pdms(pf, len);
}

void			pf_mc(t_pf *pf, va_list args)
{
	ssize_t	len;
	wchar_t	c;

	c = va_arg(args, wchar_t);
	len = pf_wclen(c);
	handle_pds(pf, len);
	pf_putwc(pf, c);
	handle_pdms(pf, len);
}

void			pf_c(t_pf *pf, va_list args)
{
	char	c;

	if (pf->job->len == 'l')
	{
		pf_mc(pf, args);
		return ;
	}
	c = (char)va_arg(args, int);
	handle_pds(pf, 1);
	if (pf->job->flags % 7 == 0 && pf->job->minw > 0)
		pf_putc(pf, '0', pf->job->minw - 1);
	pf_putc(pf, c, 1);
	handle_pdms(pf, 1);
}
