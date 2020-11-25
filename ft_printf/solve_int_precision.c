/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_int_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:36:09 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		solve_int_precision(char *to_print, int *pre)
{
	if (!pre)
		return (write(1, to_print, ft_strlen(to_print)));
	if (pre[1] == 11)
	{
		pre[0] = pre[2];
		pre[1] = 1;
		if (to_print[0] == '-')
		{
			if ((int)ft_strlen(to_print) == 2 && to_print[1] == '0'
				&& pre[0] == 0)
				return (0);
			pre[0]++;
		}
		if ((int)ft_strlen(to_print) == 1 && to_print[0] == '0' && pre[0] == 0)
			return (0);
	}
	if (pre[1] == 3)
	{
		if (to_print[0] == '0' && ft_strlen(to_print) == 1)
			return (solve_num_point_num_cero(pre));
		else if (to_print[0] == '-')
			return (solve_num_point_num_neg(to_print, pre, 0));
		return (solve_num_point_num(to_print, pre, 0));
	}
	return (solve_int_precision2(to_print, pre));
}

int		solve_int_precision2(char *to_print, int *pre)
{
	int res;

	if (pre[1] == 10)
		return (0);
	if (pre[1] == 7)
		return (solve_int_precision3(to_print, pre));
	if (pre[1] == 1 && pre[0] > 0 && (int)ft_strlen(to_print) < pre[0])
		return (solve_cero(to_print, pre));
	res = 0;
	while (pre[0] > 0 && pre[0] > (int)ft_strlen(to_print))
	{
		write(1, " ", 1);
		res++;
		pre[0]--;
	}
	write(1, to_print, ft_strlen(to_print));
	while (pre[0] < 0 && (pre[0] * -1) > (int)ft_strlen(to_print))
	{
		write(1, " ", 1);
		res++;
		pre[0]++;
	}
	return (res + ft_strlen(to_print));
}

int		solve_int_precision3(char *to_print, int *pre)
{
	int	res;
	int	min;

	min = 0;
	res = ft_strlen(to_print);
	if (to_print[0] == '-')
	{
		write(1, to_print++, 1);
		min = 1;
	}
	if (to_print[0] == '0' && ft_strlen(to_print) == 1)
		return (solve_min_num_point_num_cero(pre));
	while (pre[2] > (int)ft_strlen(to_print))
	{
		write(1, "0", 1);
		res++;
		pre[2]--;
	}
	write(1, to_print, ft_strlen(to_print));
	while (pre[0] > res)
	{
		write(1, " ", 1);
		res++;
	}
	return (res);
}

int		solve_cero(char *to_print, int *pre)
{
	int	res;
	int	icero;

	res = 0;
	icero = 0;
	if (to_print[0] == '-')
	{
		to_print++;
		icero = 1;
		write(1, "-", 1);
	}
	while (pre[0] > 0 && pre[0] > (int)ft_strlen(to_print) + icero)
	{
		write(1, "0", 1);
		res++;
		pre[0]--;
	}
	write(1, to_print, ft_strlen(to_print));
	return (res + ft_strlen(to_print) + icero);
}

int		solve_num_point_num(char *to_print, int *pre, int res)
{
	if ((int)ft_strlen(to_print) == ft_max(pre[0], pre[2], ft_strlen(to_print)))
		return (solve_int_precision(to_print, NULL));
	else if (pre[0] > (int)ft_strlen(to_print)
		&& pre[2] > (int)ft_strlen(to_print))
	{
		res = ft_max(pre[0], pre[2], 0);
		while (pre[0]-- > pre[2])
			write(1, " ", 1);
		while (pre[2]-- > (int)ft_strlen(to_print))
			write(1, "0", 1);
	}
	else if (pre[0] > (int)ft_strlen(to_print))
	{
		res = pre[0];
		while (pre[0]-- > (int)ft_strlen(to_print))
			write(1, " ", 1);
	}
	else
	{
		res = pre[2];
		while (pre[2]-- > (int)ft_strlen(to_print))
			write(1, "0", 1);
	}
	write(1, to_print, ft_strlen(to_print));
	return (res);
}
