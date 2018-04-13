/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:48:32 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/10 01:38:35 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	pf_putwc(t_pf *pf, wchar_t c)
{
	if (MB_CUR_MAX == 1 && c <= 255)
		pf_putc(pf, c, 1);
	else if (MB_CUR_MAX == 1 && c > 255 && (pf->err = 1))
		return ;
	else if (c <= 127)
		pf_putc(pf, c, 1);
	else if (c <= 2047)
	{
		pf_putc(pf, 0xC0 + (c >> 6), 1);
		pf_putc(pf, 0x80 + (0x3F & c), 1);
	}
	else if (c <= 0xFFFF)
	{
		pf_putc(pf, 0xE0 + (c >> 12), 1);
		pf_putc(pf, 0x80 + (0x3F & (c >> 6)), 1);
		pf_putc(pf, 0x80 + (0x3F & c), 1);
	}
	else if (c <= 0x1FFFFF)
	{
		pf_putc(pf, 0xF0 + (c >> 18), 1);
		pf_putc(pf, 0x80 + (0x3F & (c >> 12)), 1);
		pf_putc(pf, 0x80 + (0x3F & (c >> 6)), 1);
		pf_putc(pf, 0x80 + (0x3F & c), 1);
	}
}

size_t	pf_wclen(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x1FFFFF)
		return (4);
	return (0);
}

size_t	pf_wcslen(wchar_t *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len += pf_wclen(*s);
		s++;
	}
	return (len);
}

void	pf_putws(t_pf *pf, wchar_t *s, size_t n)
{
	while (n && s && *s)
	{
		if (n >= pf_wclen(*s))
		{
			pf_putwc(pf, *s);
			n -= pf_wclen(*s);
			s++;
		}
		else
			return ;
	}
}
