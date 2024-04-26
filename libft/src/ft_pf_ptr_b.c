/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ptr_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:39:33 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:45 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_pf_ptr_null(t_print *tab)
{
	int	count;

	count = 0;
	if (tab->dash)
		count += ft_p_str("(nil)");
	count += ft_fill_z_s(tab->wdt, 5, 0);
	if (!tab->dash)
		count += ft_p_str("(nil)");
	return (count);
}

int	ft_pf_ptr(unsigned long long n, t_print *tab)
{
	int	count;

	count = 0;
	if (n <= 0)
		return (ft_pf_ptr_null(tab));
	if (tab->zero)
		count += ft_p_str("0x");
	else if (tab->dash)
		count += ft_p_str("0x") + ft_p_hex(n, 0);
	else if (tab->sign || tab->sp)
		tab->wdt--;
	count += ft_fill_z_s(tab->wdt, ft_hex_size(n) + 2, tab->zero);
	if (tab->sign)
		count += ft_p_char('+');
	else if (tab->sp)
		count += ft_p_char(' ');
	if (tab->zero)
		count += ft_p_hex(n, 0);
	else if (!tab->dash)
		count += ft_p_str("0x") + ft_p_hex(n, 0);
	return (count);
}
