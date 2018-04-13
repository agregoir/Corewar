/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 13:41:48 by agregoir          #+#    #+#             */
/*   Updated: 2017/09/14 13:11:36 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_zero(const char *s, t_flags *flags)
{
	size_t		index;
	char		*str;
	static int	backslash = 0;

	if (flags)
		backslash = flags->backslashno;
	else
		backslash = 0;
	str = (char*)s;
	index = 0;
	while (str[index] == '\0' && backslash != 0)
	{
		index++;
		backslash--;
	}
	while (str[index] || backslash > 0)
	{
		index++;
		if (s[index] == '\0' && backslash > 0)
		{
			index++;
			backslash -= 1;
		}
	}
	return (index);
}

void	ft_putstr_zero(char const *s, t_flags *flags)
{
	int		index;

	index = ft_strlen_zero(s, flags);
	write(1, s, index);
}

char	*ft_strcat_zero(char *s1, const char *s2, t_flags *flags)
{
	size_t	index;
	size_t	counter;

	counter = 0;
	index = ft_strlen_zero(s1, flags);
	if (s2[counter] == '\0')
	{
		s1[index] = '\0';
		return (s1);
	}
	while (s2[counter] != '\0')
	{
		s1[index] = s2[counter];
		index++;
		counter++;
	}
	s1[index] = '\0';
	return (s1);
}

char	*ft_strncat_ze(char *s1, const char *s2, size_t n, t_flags *f)
{
	size_t	index;
	size_t	counter;

	counter = 0;
	index = ft_strlen_zero(s1, f);
	while (counter < n)
	{
		s1[index] = s2[counter];
		index++;
		counter++;
	}
	s1[index] = '\0';
	return (s1);
}

char	*ft_strjoin_free_ze(char *s1, char *s2, int x, t_flags *flags)
{
	char	*str;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_zero(s1, flags) + ft_strlen(s2);
	ft_strlen(s2) ? len : (len += 1);
	str = (char *)ft_memalloc(sizeof(*str) * (len + 666));
	if (str == NULL)
		return (NULL);
	if (!(ft_strncpy(str, s1, ft_strlen_zero(s1, flags) + 1)))
		return (NULL);
	if (!(ft_strncat_ze(str, s2, ft_strlen(s2), flags)))
		return (NULL);
	if (x == 1 || x == 3)
	{
		ft_strclr(s1);
		free(s1);
	}
	if (x == 2 || x == 3)
	{
		ft_strclr(s2);
		free(s2);
	}
	return (str);
}
