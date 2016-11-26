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

char	*ft_realloc_gnl(char *ptr, size_t size)
{
	char	*tmp;
	size_t 	i;

	tmp = ptr;
	i = 0;
	if (!(ptr = (char *)malloc(size)))
		return (NULL);
	while(i < size)
	{
		ptr[i] = tmp[i];
		i++;
	}
	return (ptr);
}

int			get_next_line(const int fd, char **line)
{
	static char	*curr_line;
	char		*tmp;
	int			i;
	int			pos;

	pos = 0;
	if (!curr_line)
	{
		if (!(curr_line = (char *)malloc(BUFF_SIZE)))
			return (-1);
	}
	if (!(tmp = (char *)malloc(BUFF_SIZE)))
		return (-1);
	while (read(fd, curr_line, BUFF_SIZE) > 0)
	{
		i = 0;
		while (i < BUFF_SIZE)
		{
			tmp[i + (BUFF_SIZE * pos)] = curr_line[i];
			if (curr_line[i] == '\n')
			{
				curr_line = curr_line + i + 1;
				*line = tmp;
				return (1);
			}
			i++;
		}
		pos++;
		tmp = ft_realloc_gnl(tmp, BUFF_SIZE * (pos + 1));
	}
	*line = tmp;
	return (0);
}