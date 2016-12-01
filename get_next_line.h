/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:19:12 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/22 18:19:13 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# define BUFF_SIZE 10
#include "libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_lst
{
	int				fd;
	char			*curr_line;
	struct s_lst	*next;
}					t_lst;

int				get_next_line(const int fd, char **line);
char			*ft_realloc_gnl(char *ptr, size_t size);
#endif