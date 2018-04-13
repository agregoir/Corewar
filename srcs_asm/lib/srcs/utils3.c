/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 06:11:21 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/17 21:38:26 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "printf.h"

intmax_t	pf_fetch_d(t_pf *pf, va_list args)
{
	char		len_mod;
	intmax_t	ret;

	len_mod = pf->job->len;
	if (len_mod == 'i')
		ret = (intmax_t)((char)va_arg(args, int));
	else if (len_mod == 'h')
		ret = (intmax_t)((short)va_arg(args, int));
	else if (len_mod == 'l')
		ret = (intmax_t)((long)va_arg(args, long));
	else if (len_mod == 'm')
		ret = (intmax_t)((long long)va_arg(args, long long));
	else if (len_mod == 'j')
		ret = (intmax_t)va_arg(args, intmax_t);
	else if (len_mod == 'z')
		ret = (intmax_t)((ssize_t)va_arg(args, ssize_t));
	else
		ret = (int)va_arg(args, int);
	return (ret);
}

uintmax_t	pf_fetch_u(t_pf *pf, va_list args)
{
	char		len_mod;
	uintmax_t	ret;

	len_mod = pf->job->len;
	if (len_mod == 'i')
		ret = (uintmax_t)((t_uc)va_arg(args, int));
	else if (len_mod == 'h')
		ret = (intmax_t)((t_us)va_arg(args, int));
	else if (len_mod == 'l')
		ret = (uintmax_t)((t_ul)va_arg(args, t_ul));
	else if (len_mod == 'm')
		ret = (uintmax_t)((t_ull)va_arg(args, t_ull));
	else if (len_mod == 'j')
		ret = (uintmax_t)va_arg(args, uintmax_t);
	else if (len_mod == 'z')
		ret = (uintmax_t)((size_t)va_arg(args, size_t));
	else
		ret = (t_ui)va_arg(args, t_ui);
	return (ret);
}

size_t		pf_nb_size(uintmax_t nbr, uintmax_t base)
{
	size_t	count;

	count = 0;
	if (nbr < base)
		return (1);
	while (nbr)
	{
		count++;
		nbr = nbr / base;
	}
	return (count);
}

void		pf_putint(t_pf *pf, intmax_t nbr, char *base)
{
	size_t		i;
	intmax_t	b;
	size_t		c;
	char		p;
	char		*buff;

	b = (intmax_t)ft_strlen(base);
	i = pf_nb_size(ABS(nbr), b);
	p = (nbr < 0);
	i = MAX(i, pf->job->prec > 0 ? (size_t)pf->job->prec : 0);
	i = nbr == 0 && pf->job->prec == 0 ? 0 : i;
	i += pf->job->flags % 3 == 0 || p;
	if (pf->job->flags % 2 && pf->job->prec == -1 && pf->job->flags % 7 == 0)
		i = MAX(i, pf->job->minw);
	if ((c = i) < pf->left)
		flush_buff(pf);
	buff = pf->pos;
	while (i-- > (p || pf->job->flags % 3 == 0))
	{
		buff[i] = base[ABS(nbr % b)];
		nbr = nbr / b;
	}
	if (p == 1 || pf->job->flags % 3 == 0)
		buff[0] = pf->job->flags % 3 == 0 && p == 0 ? '+' : '-';
	update_nums(pf, c);
}

void		pf_putuint(t_pf *pf, uintmax_t nbr, char *base)
{
	size_t		i;
	uintmax_t	b;
	size_t		c;
	char		*buff;

	b = (uintmax_t)ft_strlen(base);
	i = pf_nb_size(nbr, b);
	i = MAX(i, pf->job->prec > 0 ? (size_t)pf->job->prec : 0);
	i = nbr == 0 && pf->job->prec == 0 ? 0 : i;
	if (pf->job->flags % 2 && pf->job->prec == -1 && pf->job->flags % 7 == 0)
		i = MAX(i, pf->job->minw);
	if ((c = i) < pf->left)
		flush_buff(pf);
	buff = pf->pos;
	while (i--)
	{
		buff[i] = base[nbr % b];
		nbr = nbr / b;
	}
	update_nums(pf, c);
}
