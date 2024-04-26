/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:48:37 by fcoullou          #+#    #+#             */
/*   Updated: 2024/04/02 16:02:43 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.xpm_ptr = mlx_new_image(window.mlx, w, h);
	image.addr = mlx_get_data_addr(image.xpm_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

t_img	new_file_img(char *path, t_win win, t_slice slice)
{
	t_img	i;

	i.win = win;
	i.xpm_ptr = mlx_xpm_file_to_image(win.mlx, path, &slice.w, &slice.h);
	if (!i.xpm_ptr)
		ft_printf("File could not be read\n");
	else
		i.addr = mlx_get_data_addr(i.xpm_ptr, &(i.bpp),
				&(i.line_len), &(i.endian));
	return (i);
}

void	put_px_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_px_img(t_img *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_len)
			+ (x * img->bpp / 8))));
}

t_list	*ft_lstget(t_list *lst, int index)
{
	t_list	*n;
	int		i;

	i = 0;
	n = lst;
	if (n == NULL)
		return (NULL);
	if (n->next == NULL)
		return (n);
	while (n != NULL)
	{
		if (i >= index)
			return (n);
		n = n->next;
		i++;
	}
	return (NULL);
}
