/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:16:38 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:17:32 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_is_in_set(char c, const char *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	ft_trimbeg(char const *s1, char const *set)
{
	size_t	lenset;
	size_t	i;

	i = 0;
	lenset = ft_strlen(set);
	while (s1[i] && ft_is_in_set(s1[i], set) == 1)
		i++;
	return (i);
}

int	ft_trimend(char const *s2, char const *set)
{
	size_t	len;
	size_t	lenset;
	size_t	i;

	i = 0;
	lenset = ft_strlen(set);
	len = ft_strlen(s2);
	while (s2[i] && ft_is_in_set(s2[len - i - 1], set))
		i++;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	beg;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	beg = ft_trimbeg(s1, set);
	end = ft_trimend(s1 + beg, set);
	if (end <= 0)
		return (ft_strdup(""));
	dest = (char *)malloc((end + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < end)
	{
		dest[i] = s1[beg + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
