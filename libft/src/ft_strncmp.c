/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:39:54 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:17:23 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*t1 != *t2)
		{
			return (*t1 - *t2);
		}
		if (*t1 == '\0')
		{
			return (0);
		}
		t1++;
		t2++;
		n--;
	}
	return (0);
}
