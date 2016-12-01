/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <arlecomt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:02:54 by arlecomt          #+#    #+#             */
/*   Updated: 2016/12/01 15:02:54 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*ft_createlst(const int fd, t_lst *tmp)
{
	if (!tmp)
	{
		if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
			return (NULL);
		tmp->fd = fd;
		if (!(tmp->curr_line = (char *)malloc(BUFF_SIZE + 1)))
			return (NULL);
		tmp->next = NULL;
	}
	else if (tmp->fd != fd)
	{
		tmp = tmp->next;
		if (!(tmp = (t_lst *)malloc(sizeof(tmp))))
			return (NULL);
		if (!(tmp->curr_line = (char *)malloc(BUFF_SIZE + 1)))
			return (NULL);
		tmp->next = NULL;
		tmp->fd = fd;
	}
	return (tmp);
}

char		*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char			*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strncat(str, s2, n);
	return (str);
}

int		ft_test(char *temp)
{
	int			i;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0')
		return (1);
	else
		return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_lst		*lst;
	char				*tmp;
	int					pos;
	int					i;

	i = 0;
	pos = 0;
	if (!(tmp = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	lst = ft_createlst(fd, lst);
	if (ft_test(lst->curr_line) == 1)
	{
		tmp = ft_strjoin(tmp, lst->curr_line);
		ft_bzero(lst->curr_line, BUFF_SIZE);
	}
	else
	{
		tmp = ft_strnjoin(tmp, lst->curr_line, ft_test(lst->curr_line));
		i = ft_test(lst->curr_line);
		while (lst->curr_line[i] == '\n')
				i++;
		lst->curr_line = lst->curr_line + i;
		*line = tmp;
		return (1);
	}
	while (read(lst->fd, lst->curr_line, BUFF_SIZE) > 0)
	{
		lst->curr_line[BUFF_SIZE] = '\0';
		if (ft_strchr(lst->curr_line, '\n'))
		{
			while (lst->curr_line[i] != '\n')
				i++;
			tmp = ft_strnjoin(tmp, lst->curr_line, i);
			while (lst->curr_line[i] == '\n')
				i++;
			lst->curr_line = lst->curr_line + i;
			*line = tmp;
			return (1);
		}
		pos++;
		tmp = ft_strjoin(tmp, lst->curr_line);
		ft_bzero(lst->curr_line, BUFF_SIZE);
	}
	*line = tmp;
	return (0);
}
