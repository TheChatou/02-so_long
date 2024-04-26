/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_n_count_bonus copy.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:28:50 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 12:23:09 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_fill_z_s(int wdt, int size, int is_zero)
{
	int	count;

	count = 0;
	while (wdt - size > 0)
	{
		if (is_zero)
			count += ft_p_char('0');
		else
			count += ft_p_char(' ');
		wdt--;
	}
	return (count);
}

int	ft_fill_prc(int size, t_print *tab)
{
	int	count;

	count = 0;
	if (tab->wdt > size)
		count += ft_fill_z_s(tab->wdt, tab->prc, 0);
	count += ft_fill_z_s(tab->prc, size, 1);
	return (count);
}
