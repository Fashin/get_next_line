/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:06:00 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/24 15:10:39 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("File name missing\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	get_next_line(fd, &line);
	printf("%s", line);
	get_next_line(fd, &line);
	printf("%s", line);
	get_next_line(fd, &line);
	printf("%s", line);
	close(fd);
	return (0);
}
