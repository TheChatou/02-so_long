/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:28:51 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:16:34 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*e;

	i = 0;
	d = (char *)dest;
	e = (char *)src;
	if (dest < src)
	{	
		while (i < n)
		{
			d[i] = e[i];
			i++;
		}
	}	
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = e[i];
		}
	}
	return (d);
}
