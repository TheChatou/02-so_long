/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 22:03:03 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/24 14:05:49 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*get_next_line(int fd)
{
	static t_fd_buf	fb[MAX_FD] = {{.buf.n_read = 0, .buf.pos = 0}};
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	line = (char *) malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	if (fb[fd].buf.n_read && fb[fd].buf.pos < fb[fd].buf.n_read)
		line = ft_cat(line, &(fb[fd].buf));
	if (ft_strchr(line, '\n'))
		return (line);
	fb[fd].buf.n_read = 1;
	while (fb[fd].buf.n_read)
	{
		fb[fd].buf.n_read = read(fd, fb[fd].buf.buf, BUFFER_SIZE);
		if (!init_buf(&(fb[fd].buf), line))
			return (NULL);
		line = ft_cat(line, &(fb[fd].buf));
		if (ft_strchr(line, '\n') || line[0] == '\n')
			return (line);
	}
	return (line);
}

char	*ft_cat(char *line, t_buf *buf)
{
	char	*new;
	int		i;
	int		len_line;

	i = 0;
	len_line = ft_strlen(line);
	while (buf->buf[buf->pos + i] && buf->buf[buf->pos + i] != '\n')
		i++;
	if (buf->buf[buf->pos + i] == '\n')
		i++;
	new = (char *)malloc((len_line + i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, line, len_line);
	free(line);
	ft_memcpy(new + len_line, &buf->buf[buf->pos], i);
	new[len_line + i] = '\0';
	buf->pos += i;
	return (new);
}

int	init_buf(t_buf *buf, char *line)
{
	if (!buf->n_read && buf->buf[buf->pos - 1] == '\n')
	{
		free(line);
		return (0);
	}
	if (buf->n_read < 0 || (buf->n_read == 0 && buf->buf[0] == '\0')
		|| (buf->n_read == 0 && buf->buf[0] == '\n' && !buf->buf[1]))
	{
		free(line);
		return (0);
	}
	buf->buf[buf->n_read] = 0;
	buf->pos = 0;
	return (1);
}

int	ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (((unsigned char)s[0] == (unsigned char)c) && !s[1])
			return (1);
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (0);
}
