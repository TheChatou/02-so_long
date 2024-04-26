/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dec_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:09:20 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:32 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_p_dec(long int n)
{
	if (n < 0)
		return (ft_p_char('-') + ft_p_dec(n * -1));
	else if (n < 10)
		return (ft_p_char(n + '0'));
	else
		return (ft_p_dec(n / 10) + ft_p_dec(n % 10));
}

int	ft_pf_dec_neg(long int *n, t_print *tab, int *printed)
{
	int	count;

	count = 0;
	count += ft_p_char('-');
	if (tab->dash && tab->prc >= 0 && tab->wdt > tab->prc)
	{
		*printed = 1;
		count += ft_fill_z_s(tab->prc, ft_int_size(-(*n)), 1);
		count += ft_p_dec(-(*n));
		count += ft_fill_z_s(tab->wdt - 1, tab->prc, 0);
		return (count);
	}
	else if (tab->prc >= 0)
		count += ft_fill_z_s(tab->prc, ft_int_size(-(*n)), 1);
	else
		count += ft_fill_z_s(tab->wdt, ft_int_size(*n), tab->zero);
	*n *= -1;
	return (count);
}

int	ft_pf_dec_dash_prc(long int n, t_print *tab)
{
	int	count;
	int	printed;

	printed = 0;
	count = 0;
	if (n < 0 && tab->prc >= 0)
		count += ft_pf_dec_neg(&n, tab, &printed);
	else if (tab->prc > ft_int_size(n) && tab->prc >= tab->wdt)
		count += ft_fill_prc(ft_int_size(n), tab);
	else if (tab->dash && n >= 0)
	{
		printed = 1;
		if (tab->wdt > tab->prc)
			count += ft_fill_z_s(tab->prc, ft_int_size(n), 1);
		count += ft_p_dec(n);
		if (count != tab->wdt)
			count += ft_fill_z_s(tab->wdt, count, 0);
	}
	else
		count += ft_fill_z_s(tab->wdt, ft_int_size(n), tab->zero);
	if (!printed)
		count += ft_p_dec(n);
	return (count);
}

int	ft_pf_dec_zero_prc(long int n, t_print *tab)
{
	int	count;

	count = 0;
	if (tab->wdt > tab->prc && n < 0 && tab->prc > ft_int_size(n))
		count += ft_fill_z_s(tab->wdt - 1, tab->prc, 0);
	else if (tab->wdt > tab->prc && n < 0)
		count += ft_fill_z_s(tab->wdt, ft_int_size(n), 0);
	else if (tab->wdt > tab->prc && n >= 0 && ft_int_size(n) > tab->prc)
		count += ft_fill_z_s(tab->wdt, ft_int_size(n), 0);
	else if (tab->wdt > tab->prc && n >= 0)
	{
		count += ft_fill_z_s(tab->wdt, tab->prc, 0);
		count += ft_fill_z_s(tab->prc, ft_int_size(n), 1);
	}
	else if (tab->prc >= tab->wdt && n >= 0)
		count += ft_fill_prc(ft_int_size(n), tab);
	else if (n > 0)
		count += ft_fill_z_s(tab->wdt, ft_int_size(n), tab->zero);
	if (n < 0)
		count += ft_pf_dec_neg(&n, tab, 0);
	count += ft_p_dec(n);
	return (count);
}

int	ft_pf_dec(long int n, t_print *tab, int count)
{
	if (!n && !tab->prc)
		return (count + ft_fill_z_s(tab->wdt, 0, 0));
	if (tab->dash && tab->prc >= 0)
		return (ft_pf_dec_dash_prc(n, tab));
	else if (tab->dash)
		count += ft_p_dec(n);
	else if (tab->zero && tab->prc >= 0)
		return (ft_pf_dec_zero_prc(n, tab));
	else if (tab->sign || tab->sp)
		tab->wdt--;
	if (n < 0 && (tab->zero || tab->prc >= 0))
		count += ft_pf_dec_neg(&n, tab, 0);
	else if (tab->prc >= 0 && tab->prc > ft_int_size(n))
		count += ft_fill_prc(ft_int_size(n), tab);
	else
		count += ft_fill_z_s(tab->wdt, ft_int_size(n), tab->zero);
	if (tab->sign && n >= 0)
		count += ft_p_char('+');
	else if (tab->sp && n >= 0)
		count += ft_p_char(' ');
	if (!tab->dash)
		count += ft_p_dec(n);
	return (count);
}
