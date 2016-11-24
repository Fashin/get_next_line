/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:19:06 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/22 18:19:07 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		*curr_line;
	int				i;
	int				pos;

	i = 0;
	pos = 1;
	ft_memdel((void **)line);
	if (!(curr_line = (char *)malloc(BUFF_SIZE)))
		return (-1);
	while (read(fd, curr_line, BUFF_SIZE) > 0)
	{
		while (i < BUFF_SIZE)
		{
			if (curr_line[i] == '\n')
				return (1);
			write(1, &curr_line[i], 1);
			i++;
		}
		i = 0;
		pos++;
		if (pos != 2)
			*line = ft_realloc(*line, BUFF_SIZE * pos);
		*line = ft_strcat(*line, curr_line);
	}
	return (0);
}

/*
ret = curr_line;
		while (i < BUFF_SIZE)
		{
			if (ret[i] == '\n')
				return (1);
			write(1, &ret[i], 1);
			i++;
		}
		i = 0;
		pos++;

		*line = ft_realloc(*line, BUFF_SIZE * pos);
		*line = ft_strcat(*line, ret);
*/