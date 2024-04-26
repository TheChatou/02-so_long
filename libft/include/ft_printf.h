/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoullou <fcoullou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:56:16 by fcoullou          #+#    #+#             */
/*   Updated: 2024/03/25 13:51:25 by fcoullou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct s_print
{
	va_list			args;
	int				type;
	int				dash;
	int				zero;
	int				prc;
	int				sharp;
	int				sign;
	int				sp;
	int				wdt;
}	t_print;

int			ft_printf(const char *str, ...);

int			ft_pf_char(char c, t_print *tab);
int			ft_p_char(char c);

int			ft_pf_str(char *str, t_print *tab);
int			ft_p_str(char *str);

int			ft_pf_ptr(unsigned long long n, t_print *tab);
int			ft_pf_ptr_null(t_print *tab);

int			ft_pf_dec(long int n, t_print *tab, int count);
int			ft_pf_dec_zero_prc(long int n, t_print *tab);
int			ft_pf_dec_dash_prc(long int n, t_print *tab);
int			ft_pf_dec_neg(long int *n, t_print *tab, int *printed);
int			ft_p_dec(long int n);

int			ft_pf_uint(unsigned int n, t_print *tab);
int			ft_pf_uint_zero_prc(long int n, t_print *tab);
int			ft_pf_uint_dash_prc(long int n, t_print *tab);
int			ft_p_uint(unsigned int n);

int			ft_pf_hex(unsigned int n, char base, t_print *tab);
int			ft_pf_hex_zero_prc(long int n, t_print *tab, char base);
int			ft_pf_hex_dash_prc(long int n, t_print *tab, char base);
int			ft_p_hex(unsigned long int n, char base);

int			ft_uint_size(unsigned long n);
int			ft_int_size(long int n);
int			ft_hex_size(unsigned long int n);

int			ft_fill_prc(int size, t_print *tab);
int			ft_fill_z_s(int wdt, int size, int is_zero);

int			ft_isflag(int c);
int			ft_istype(int c);
int			ft_isflagtype(int c);
int			ft_flags_prc(const char *str, int i, t_print *tab);
t_print		init_tab(void);

#endif