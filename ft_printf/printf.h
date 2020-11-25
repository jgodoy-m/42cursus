/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:02:36 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/23 22:14:41 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *src, ...);
int		get_flag(const char *src, va_list args, int *i);
int		c_flag(va_list args, int *pre);
int		s_flag(va_list args, int *pre);
int		p_flag(va_list args, int *pre);
int		i_flag(va_list args, int *pre);
int		d_flag(va_list args, int *pre);
int		u_flag(va_list args, int *pre);
int		x_flag(va_list args, int *pre);
int		xx_flag(va_list args, int *pre);
int		per_flag(int *pre);
char	*ft_itoaus(unsigned int n);
int		ft_min(int a, int b);
void	ft_base(unsigned long int i, char *base, int *res, char *to_print);
int		set_precision(va_list args, const char *src, int *i, int *pre);
int		star_flag(va_list args, const char *src, int *i);
int		solve_int_precision2(char *to_print, int *pre);
int		solve_cero(char *to_print, int *pre);
int		minus_flag(va_list args, const char *src, int *i);
int		number_flag(va_list args, const char *src, int *i);
int		point_flag(va_list args, const char *src, int *i, int aux);
int		solve_point(va_list args, const char *src, int *i, int aux);
int		solve_min_point(va_list args, const char *src, int *i, int *pre);
int		set_num_point_num(va_list args, const char *src, int *i, int *pre);
int		solve_num_point_num(char *to_print, int *pre, int res);
int		solve_int_precision(char *to_print, int *pre);
int		ft_abs(int a);
int		solve_char_precision(char *to_print, int *pre);
int		solve_str_precision(char *to_print, int *pre);
int		solve_str_num_point_num(char *to_print, int *pre);
int		set_min_star(va_list args, const char *src, int *i);
int		ft_max(int a, int b, int c);
int		solve_num_point_num_cero(int *pre);
int		solve_num_point_num_neg(char *to_print, int *pre, int res);
int		solve_min_num_point_num(va_list ar, const char *s, int *i, int *p);
int		solve_str_min_num_point(char *to_print, int *pre);
int		solve_min_num_point_num_cero(int *pre);
int		solve_p_precision(char *to_print, int *pre);
int		solve_p_num_point_num(char *to_print, int *pre, int res);
int		solve_int_precision3(char *to_print, int *pre);
int		set_min_star_point(va_list args, const char *src, int *i, int *pre);
int		set_star_point(va_list args, const char *src, int *i, int *pre);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *src);
char	*ft_itoa(int n);
int		solve_num_point_num_neg2(char *to_print, int *pre, int res);
int		set_star_point_star(va_list args, const char *src, int *i, int *pre);
int		set_min_star_point_star2(va_list ar, const char *s, int *i, int *p);

#endif
