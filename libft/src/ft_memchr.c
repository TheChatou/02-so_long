/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:39:37 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:16:20 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int		i;
	char				*d;

	i = 0;
	d = (char *)s;
	while (i < n)
	{
		if ((unsigned char)d[i] == (unsigned char)c)
			return ((unsigned char *)&d[i]);
		i++;
	}
	return (NULL);
}
