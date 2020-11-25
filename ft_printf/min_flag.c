/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:34:58 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		minus_flag(va_list args, const char *src, int *i)
{
	int	pre[3];
	int	aux;

	*i += 1;
	if (src[*i] >= '0' && src[*i] <= '9')
		pre[0] = ft_atoi(src + *i);
	if (src[*i] == '*')
		return (set_min_star(args, src, i));
	while (src[*i] >= '0' && src[*i] <= '9')
		*i += 1;
	if (src[*i] == '.' && src[*i += 1] == 's')
	{
		aux = pre[0];
		while (aux-- > 0)
			write(1, " ", 1);
		return (pre[0]);
	}
	else if (src[*i - 1] == '.')
		return (solve_min_point(args, src, i, pre));
	if (src[*i - 1] > '9' || src[*i - 1] < '0')
		return (set_precision(args, src, i, NULL));
	pre[0] *= -1;
	pre[1] = 4;
	return (set_precision(args, src, i, pre));
}

int		solve_min_point(va_list args, const char *src, int *i, int *pre)
{
	pre[1] = 7;
	pre[2] = ft_atoi(src + *i);
	if (src[*i] == '-')
		*i += 1;
	while (src[*i] >= '0' && src[*i] <= '9')
		*i += 1;
	return (set_precision(args, src, i, pre));
}

int		solve_min_num_point_num_cero(int *pre)
{
	int	res;

	if (pre[2] == 0)
	{
		res = pre[0];
		while (res-- > 0)
			write(1, " ", 1);
		return (pre[0]);
	}
	else if (pre[0] >= pre[2])
	{
		res = pre[2];
		while (res-- > 0)
			write(1, "0", 1);
		res = pre[0];
		while (res-- > pre[2])
			write(1, " ", 1);
		return (pre[0]);
	}
	res = pre[2];
	while (res-- > 0)
		write(1, "0", 1);
	return (pre[2]);
}

int		set_min_star_point(va_list args, const char *src, int *i, int *pre)
{
	*i += 1;
	if ((src[*i] == 'c') || (src[*i] == 's') || (src[*i] == 'p') ||
		(src[*i] == 'i') || (src[*i] == 'd') || (src[*i] == 'u') ||
		(src[*i] == 'x') || (src[*i] == 'X') ||
		(src[*i] == '%'))
	{
		pre[1] = 0;
		return (set_precision(args, src, i, pre));
	}
	pre[0] = ft_abs(pre[0]);
	pre[1] = 7;
	if (src[*i] == '*')
		return (set_min_star_point_star2(args, src, i, pre));
	if (src[*i] <= '9' && src[*i] >= '0')
	{
		pre[2] = ft_atoi(src + *i);
		while (src[*i] <= '9' && src[*i] >= '0')
			*i += 1;
		return (set_precision(args, src, i, pre));
	}
	return (0);
}

int		set_min_star_point_star2(va_list args, const char *src, int *i, int *p)
{
	int	input;

	input = (int)va_arg(args, int);
	if (input < 0)
		p[2] = 1000;
	else
		p[2] = input;
	*i += 1;
	return (set_precision(args, src, i, p));
}
