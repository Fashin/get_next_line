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
	char			*tmp;

	curr_line = ft_memalloc(BUFF_SIZE);
	while (read(fd, curr_line, BUFF_SIZE) > 0)
		tmp = ft_strjoin(tmp, curr_line);
	if (!(*line = (char *)malloc(ft_strlen(tmp))))
		return (-1);
	*line = tmp;
	while (**line != '\0' && **line != '\n')
	{
		write(1, *line, 1);
		*line += 1;
	}
	return (0);
}
