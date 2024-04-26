/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:47:01 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:16:29 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*e;

	i = 0;
	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	e = (char *)src;
	while (i < n)
	{
		d[i] = e[i];
		i++;
	}
	return (d);
}
