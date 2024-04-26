/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus copy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:10:02 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 12:23:12 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_print	init_tab(void)
{
	t_print	tab;

	tab.type = 0;
	tab.dash = 0;
	tab.zero = 0;
	tab.prc = -1;
	tab.sharp = 0;
	tab.sign = 0;
	tab.sp = 0;
	tab.wdt = 0;
	return (tab);
}

int	ft_flags_prc(const char *str, int i, t_print *tab)
{
	i++;
	tab->prc = 0;
	while (ft_isdigit(str[i]))
	{
		tab->prc = (tab->prc * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int	ft_isflagtype(int c)
{
	if (ft_strchr("-0.# +", c))
		return (1);
	return (0);
}

int	ft_istype(int c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	ft_isflag(int c)
{
	return (ft_istype(c) || ft_isdigit(c) || ft_isflagtype(c));
}
