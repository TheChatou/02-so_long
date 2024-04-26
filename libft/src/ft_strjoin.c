/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:28:37 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:17:07 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	dest = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	if (s1)
		ft_memcpy(dest, s1, len1);
	if (s2)
		ft_memcpy(dest + len1, s2, len2);
	dest[len1 + len2] = '\0';
	return (dest);
}
