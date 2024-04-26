/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_hex_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:46:43 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:40 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_p_hex(unsigned long int n, char base)
{
	char	*is_base;

	if (base)
		is_base = "0123456789ABCDEF";
	else
		is_base = "0123456789abcdef";
	if (n < 16)
		return (ft_p_char(is_base[n]));
	else
		return (ft_p_hex(n / 16, base) + ft_p_hex(n % 16, base));
}

int	ft_pf_hex_dash_prc(long int n, t_print *tab, char base)
{
	int	count;
	int	printed;

	printed = 0;
	count = 0;
	if (tab->prc >= 0 && tab->prc > ft_hex_size(n)
		&& tab->prc >= tab->wdt)
		count += ft_fill_prc(ft_hex_size(n), tab);
	else
	{
		printed = 1;
		if (tab->wdt > tab->prc)
		{
			count += ft_fill_z_s(tab->prc, ft_hex_size(n), 1);
			count += ft_p_hex(n, base);
			if (count != tab->wdt)
				count += ft_fill_z_s(tab->wdt, count, 0);
		}
		else
			count += ft_p_hex(n, base);
	}
	if (!printed)
		count += ft_p_hex(n, base);
	return (count);
}

int	ft_pf_hex_zero_prc(long int n, t_print *tab, char base)
{
	int	count;

	count = 0;
	if (tab->wdt > tab->prc && ft_hex_size(n) > tab->prc)
		count += ft_fill_z_s(tab->wdt, ft_hex_size(n), 0);
	else if (tab->wdt > tab->prc)
	{
		count += ft_fill_z_s(tab->wdt, tab->prc, 0);
		count += ft_fill_z_s(tab->prc, ft_hex_size(n), 1);
	}
	else if (tab->prc >= tab->wdt)
		count += ft_fill_prc(ft_hex_size(n), tab);
	else
		count += ft_fill_z_s(tab->wdt, ft_hex_size(n), tab->zero);
	count += ft_p_hex(n, base);
	return (count);
}

int	ft_pf_hex(unsigned int n, char base, t_print *tab)
{
	int	count;

	count = 0;
	if (!n && !tab->prc)
		return (count + ft_fill_z_s(tab->wdt, 0, 0));
	if (tab->dash && tab->prc >= 0)
		return (ft_pf_hex_dash_prc(n, tab, base));
	else if (tab->dash)
		count += ft_p_hex(n, base);
	else if (tab->zero && tab->prc >= 0)
		return (ft_pf_hex_zero_prc(n, tab, base));
	if (tab->sharp)
		tab->wdt -= 2;
	if (tab->prc >= 0 && tab->prc > ft_hex_size(n))
		count += ft_fill_prc(ft_hex_size(n), tab);
	else
		count += ft_fill_z_s(tab->wdt, ft_hex_size(n), tab->zero);
	if (tab->sharp && n)
		count += ft_p_str("0") + ft_p_char(tab->type);
	if (!n && !tab->prc)
		return (count);
	if (!tab->dash)
		count += ft_p_hex(n, base);
	return (count);
}
