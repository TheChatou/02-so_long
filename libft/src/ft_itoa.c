/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:17:03 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:15:32 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	numlen(int n)
{
	size_t	count;

	count = 1;
	while (n != 0)
	{
		n /= 10;
		if (n != 0)
			count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*dest;
	long int	num;
	size_t		len;

	num = n;
	len = numlen(n);
	if (n < 0 || len == 0)
	{
		num *= -1;
		len++;
	}
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	*(dest + len) = 0;
	while (len--)
	{
		*(dest + len) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(dest + 0) = '-';
	return (dest);
}
