/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlecomt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:42:43 by arlecomt          #+#    #+#             */
/*   Updated: 2016/11/03 17:42:44 by arlecomt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	c_;
	char			*b_;

	i = 0;
	c_ = c;
	b_ = b;
	while (i < len)
	{
		b_[i] = c_;
		i++;
	}
	return (b);
}