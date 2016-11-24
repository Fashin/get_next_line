/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:58:58 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/24 16:59:14 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, int size)
{
	int		i;
	char	*save;

	i = 0;
	if (!(save = (char *)malloc(sizeof(char) * ft_strlen(str))))
	{
		write(1, "|", 1);
		return (NULL);
	}
	while (str[i])
	{
		save[i] = str[i];
		i++;
	}
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	while (save[i])
	{
		str[i] = save[i];
		i++;
	}
	free(save);
	return (str);
}
