/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:19:35 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:16:38 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	char			*d;

	i = 0;
	d = (char *)s;
	while (i < n)
	{
		d[i] = c;
		i++;
	}
	return (d);
}
