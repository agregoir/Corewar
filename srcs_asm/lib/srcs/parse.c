/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 15:23:51 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/17 22:21:02 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_job	*make_job(void)
{
	t_job	*ret;

	if (!(ret = (t_job*)malloc(sizeof(t_job))))
		exit(0);
	ret->start = NULL;
	ret->end = NULL;
	ret->flags = 1;
	ret->minw = 0;
	ret->prec = -1;
	ret->len = 0;
	ret->type = 0;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void	popul(char *str, t_job *job, va_list args)
{
	job->start = str;
	++str;
	str = get_flags(str, job);
	str = get_minw(str, job, args);
	str = get_prec(str, job, args);
	str = get_len(str, job);
	job->type = *str;
	job->end = str + 1;
}

t_job	*parse(const char *format, va_list args)
{
	char	*start;
	t_job	*head;
	t_job	*link;

	start = ft_strchr(format, '%');
	if (!start)
		return (NULL);
	popul(start, (head = make_job()), args);
	link = head;
	while ((start = ft_strchr(link->end, '%')))
	{
		popul(start, (link->next = make_job()), args);
		link->next->prev = link;
		link = link->next;
	}
	return (head);
}
