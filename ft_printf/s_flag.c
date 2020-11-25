/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:35:23 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		s_flag(va_list args, int *pre)
{
	char	*to_print;
	int		aux;

	to_print = (char *)va_arg(args, char *);
	if (!to_print)
		to_print = "(null)";
	if (pre && pre[1] == 11)
	{
		aux = ft_min((int)ft_strlen(to_print), pre[2]);
		return (write(1, to_print, aux));
	}
	if (pre && pre[1] == 7)
		return (solve_str_min_num_point(to_print, pre));
	if (pre && pre[1] != 3 && ft_abs(pre[0]) < (int)ft_strlen(to_print))
		return (write(1, to_print, ft_strlen(to_print)));
	else if (pre)
		return (solve_str_precision(to_print, pre));
	return (write(1, to_print, ft_strlen(to_print)));
}

int		solve_str_precision(char *to_print, int *pre)
{
	int	res;

	if (pre[1] == 3)
		return (solve_str_num_point_num(to_print, pre));
	if (pre[1] == 1 && pre[0] > 0 && (int)ft_strlen(to_print) + 1 <= pre[0])
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

int		solve_str_num_point_num(char *to_print, int *pre)
{
	int	aux;

	if (pre[2] == 0 && to_print[0] == '%')
	{
		pre[1] = 0;
		return (solve_int_precision(to_print, pre));
	}
	if (pre[1] == 3)
	{
		if (pre[2] < (int)ft_strlen(to_print))
		{
			aux = pre[0];
			while (pre[2] < aux--)
				write(1, " ", 1);
			write(1, to_print, pre[2]);
			return (pre[0]);
		}
		else
		{
			pre[1] = 0;
			return (solve_int_precision(to_print, pre));
		}
	}
	return (0);
}

int		solve_str_min_num_point(char *to_print, int *pre)
{
	int	res;

	if (pre[0] < (int)ft_strlen(to_print) && pre[2] < (int)ft_strlen(to_print))
		res = write(1, to_print, ft_min(pre[2], ft_strlen(to_print)));
	else
	{
		res = ft_min(ft_strlen(to_print), pre[2]);
		write(1, to_print, res);
	}
	while (res++ < pre[0])
		write(1, " ", 1);
	return (res - 1);
}
