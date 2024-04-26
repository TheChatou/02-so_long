/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_uint_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:41:08 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:52 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_p_uint(unsigned int n)
{
	if (n < 10)
		return (ft_p_char(n + '0'));
	else
		return (ft_p_uint(n / 10) + ft_p_uint(n % 10));
}

int	ft_pf_uint_dash_prc(long int n, t_print *tab)
{
	int	count;
	int	printed;

	printed = 0;
	count = 0;
	if (tab->prc > ft_uint_size(n) && tab->prc >= tab->wdt)
		count += ft_fill_prc(ft_uint_size(n), tab);
	else
	{
		printed = 1;
		if (tab->wdt > tab->prc)
		{
			count += ft_fill_z_s(tab->prc, ft_uint_size(n), 1);
			count += ft_p_uint(n);
			if (count != tab->wdt)
				count += ft_fill_z_s(tab->wdt, count, 0);
		}
		else
			count += ft_p_uint(n);
	}
	if (!printed)
		count += ft_p_uint(n);
	return (count);
}

int	ft_pf_uint_zero_prc(long int n, t_print *tab)
{
	int	count;

	count = 0;
	if (tab->wdt > tab->prc && ft_uint_size(n) > tab->prc)
		count += ft_fill_z_s(tab->wdt, ft_uint_size(n), 0);
	else if (tab->wdt > tab->prc)
	{
		count += ft_fill_z_s(tab->wdt, tab->prc, 0);
		count += ft_fill_z_s(tab->prc, ft_uint_size(n), 1);
	}
	else if (tab->prc >= tab->wdt)
		count += ft_fill_prc(ft_uint_size(n), tab);
	else
		count += ft_fill_z_s(tab->wdt, ft_uint_size(n), tab->zero);
	count += ft_p_uint(n);
	return (count);
}

int	ft_pf_uint(unsigned int n, t_print *tab)
{
	int	count;

	count = 0;
	if (!n && !tab->prc)
		return (count + ft_fill_z_s(tab->wdt, 0, 0));
	if (tab->dash && tab->prc >= 0)
		return (ft_pf_uint_dash_prc(n, tab));
	else if (tab->dash)
		count += ft_p_uint(n);
	else if (tab->zero && tab->prc >= 0)
		return (ft_pf_uint_zero_prc(n, tab));
	if (tab->prc >= 0 && tab->prc > ft_uint_size(n))
		count += ft_fill_prc(ft_uint_size(n), tab);
	else
		count += ft_fill_z_s(tab->wdt, ft_uint_size(n), tab->zero);
	if (!n && !tab->prc)
		return (count);
	if (!tab->dash)
		count += ft_p_uint(n);
	return (count);
}
