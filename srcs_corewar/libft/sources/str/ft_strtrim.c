/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:56:21 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/10 16:56:51 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			end;
	char			*str;

	if (!s)
		return (0);
	start = 0;
	while ((s[start] == ' ') || (s[start] == '\t') || (s[start] == '\n'))
		start++;
	end = ft_strlen(s) - 1;
	while (((s[end] == ' ') || (s[end] == '\t') || (s[end] == '\n')) &&
		(end > start))
		end--;
	if (end < start)
		return (str = ft_strdup(""));
	return (str = ft_strsub(s, start, end - (size_t)start + 1));
}
