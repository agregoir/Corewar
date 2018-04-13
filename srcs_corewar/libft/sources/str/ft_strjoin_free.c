/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 01:44:06 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/09 19:25:30 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char *s1, char *s2, int which_one)
{
	char	*str;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_memalloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (!(ft_strcpy(str, s1)))
		return (NULL);
	if (!(ft_strcat(str, s2)))
		return (NULL);
	if (which_one == 1 || which_one == 3)
	{
		ft_strclr(s1);
		free(s1);
	}
	if (which_one == 2 || which_one == 3)
	{
		ft_strclr(s2);
		free(s2);
	}
	return (str);
}
