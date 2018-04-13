/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agregoir <agregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 17:07:07 by agregoir          #+#    #+#             */
/*   Updated: 2017/10/10 17:07:10 by agregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cut_that_bitch(char *str, char **stock, char **line, int ret)
{
	unsigned int		i;
	char				*part[2];

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	part[0] = ft_strsub(str, 0, i);
	part[1] = ft_strsub(str, i + 1, (size_t)(ft_strlen(str + i + 1)));
	if (str == *stock)
		free(str);
	*stock = part[1];
	*line = ft_strjoin_free(*line, part[0], 3);
	if (((ft_strlen(*line) == 0) && (ft_strlen(*stock) == 0)) && (ret == 0))
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stock = NULL;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if ((BUFF_SIZE < 1) || (read(fd, buf, 0) < 0) || (!line) || (fd < 0))
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (stock && ft_strchr(stock, '\n'))
		return (cut_that_bitch(stock, &stock, line, 1));
	else if (stock)
	{
		free(*line);
		*line = ft_strdup(stock);
		free(stock);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
			return (cut_that_bitch(buf, &stock, line, ret));
		else
			*line = ft_strjoin_free(*line, buf, 1);
	}
	ft_memset(buf, 0, BUFF_SIZE);
	return (cut_that_bitch(buf, &stock, line, ret));
}
