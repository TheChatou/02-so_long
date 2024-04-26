/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:39:11 by fcoullou          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:55 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	format_to_print(char type, va_list args, t_print *tab)
{
	if (type == 'c')
		return (ft_pf_char(va_arg(args, int), tab));
	else if (type == 's')
		return (ft_pf_str(va_arg(args, char *), tab));
	else if (type == 'p')
		return (ft_pf_ptr(va_arg(args, unsigned long long), tab));
	else if (type == 'd' || type == 'i')
		return (ft_pf_dec(va_arg(args, int), tab, 0));
	else if (type == 'u')
		return (ft_pf_uint(va_arg(args, unsigned int), tab));
	else if (type == 'x')
		return (ft_pf_hex(va_arg(args, unsigned int), 0, tab));
	else if (type == 'X')
		return (ft_pf_hex(va_arg(args, unsigned int), 1, tab));
	else if (type == '%')
		return (ft_p_char('%'));
	return (0);
}

int	set_flags(const char *str, int i, int sv_i, t_print *tab)
{
	while (str[i++] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			tab->dash = 1;
		if (str[i] == '0' && !tab->wdt)
			tab->zero = 1;
		if (str[i] == '.')
			i = ft_flags_prc(str, i, tab);
		if (str[i] == '#')
			tab->sharp = 1;
		if (str[i] == '+')
			tab->sign = 1;
		if (str[i] == ' ' && !tab->sign)
			tab->sp = 1;
		if (ft_isdigit(str[i]) && tab->prc == -1)
			tab->wdt = (tab->wdt * 10) + (str[i] - '0');
		if (ft_istype(str[i]))
		{
			tab->type = str[i];
			return (i);
		}
	}
	return (sv_i);
}

int	check_flag_pattern(const char *str, int *i, va_list args)
{
	t_print		tab;
	int			count;

	count = 0;
	tab = init_tab();
	if (str[*i] == '%' && str[*i + 1])
	{
		*i = set_flags(str, *i, *i, &tab);
		if (tab.type > 0 && ft_istype(str[*i]))
			count += format_to_print(str[*i], args, &tab);
		else if (str[*i])
			count += ft_p_char(str[*i]);
	}
	else
		count += ft_p_char(str[*i]);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			i;
	int			count;

	if (!str || !str[0])
		return (0);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{			
		count += check_flag_pattern(str, &i, args);
		i++;
	}
	va_end(args);
	return (count);
}
