/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:37:32 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 11:16:53 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	splitlen(const char *s, char c)
{
	size_t		count;

	count = 0;
	while (s[count] && s[count] != c)
			count++;
	return (count);
}

size_t	wordslen(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**free_and_return_null(char **split, size_t index)
{
	while (index--)
		free(split[index]);
	free(split);
	return (NULL);
}

char	**ft_fill_dest(char const *s, char **dest, char c, size_t *i)
{
	size_t		j;
	size_t		splitword;

	j = 0;
	while (s[*i] != '\0')
	{
		while (s[*i] == c)
			*i = *i + 1;
		if (s[*i] == '\0')
		{
			dest[j] = NULL;
			return (dest);
		}
		splitword = splitlen(&s[*i], c);
		dest[j] = (char *)malloc(sizeof(char) * (splitword + 1));
		if (!dest[j])
			return (free_and_return_null(dest, j));
		ft_memcpy(dest[j], &s[*i], splitword);
		dest[j][splitword] = '\0';
		j++;
		*i += splitword;
	}
	dest[j] = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**dest;

	if (!s)
		return (NULL);
	dest = (char **) malloc (sizeof(char *) * (wordslen(s, c) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	dest = ft_fill_dest(s, dest, c, &i);
	return (dest);
}
