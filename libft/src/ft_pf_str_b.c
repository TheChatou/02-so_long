/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_str_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:09:57 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:47 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_p_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_pf_str(char *str, t_print *tab)
{
	int	len;
	int	sub_len;
	int	count;

	count = 0;
	if (!str && tab->prc >= 0 && tab->prc < 6)
		str = "";
	else if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	if (tab->prc >= 0 && tab->prc < len)
		str = ft_substr(str, 0, tab->prc);
	sub_len = (int)ft_strlen(str);
	if (tab->dash)
		count += ft_p_str(str);
	count += ft_fill_z_s(tab->wdt, sub_len, 0);
	if (!tab->dash)
		count += ft_p_str(str);
	if (tab->prc >= 0 && tab->prc < len)
		free(str);
	return (count);
}
