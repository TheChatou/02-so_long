/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:56:34 by fcoullou          #+#    #+#             */
/*   Updated: 2024/03/25 14:27:32 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.size.y)
	{
		free(map.map[i]);
		i++;
	}
	if (map.map)
		free(map.map);
}

void	free_xpms(void *mlx, void **xpms, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (xpms[i])
			mlx_destroy_image(mlx, xpms[i]);
		i++;
	}
}

void	ft_lstclear_a_xpm(t_img *img, void *mlx)
{
	if (img->xpm_ptr && mlx)
		mlx_destroy_image(mlx, img->xpm_ptr);
	free(img);
}

void	free_lst_anim(t_list **lst, void *mlx)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		ft_lstclear_a_xpm((t_img *)(*lst)->content, mlx);
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	free_anim(t_anim *anim, void *mlx)
{
	free_lst_anim(&anim->frames, mlx);
	if (anim->bigfra.xpm_ptr)
		mlx_destroy_image(mlx, anim->bigfra.xpm_ptr);
}
