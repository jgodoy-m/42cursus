/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:35:17 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		point_flag(va_list args, const char *src, int *i, int aux)
{
	int	pre[3];

	aux = *i += 1;
	while ((src[*i] >= '0' && src[*i] <= '9') || src[*i] == '*')
		*i += 1;
	if (src[*i] == 'c' || src[*i] == '%')
		return (set_precision(args, src, i, NULL));
	if (src[aux] >= '0' && src[aux] <= '9')
	{
		pre[2] = ft_atoi(src + aux);
		pre[1] = 11;
		return (set_precision(args, src, i, pre));
	}
	if (src[aux] == '*')
	{
		pre[2] = (int)va_arg(args, int);
		pre[1] = 11;
		if (pre[2] < 0)
			return (set_precision(args, src, i, NULL));
		return (set_precision(args, src, i, pre));
	}
	if (src[*i] == 's')
		return (write(1, "", 0));
	pre[1] = 10;
	return (set_precision(args, src, i, pre));
}

int		set_num_point_num(va_list args, const char *src, int *i, int *pre)
{
	pre[1] = 3;
	if (src[*i + 1] == '*')
	{
		pre[2] = (int)va_arg(args, int);
		if (pre[2] < 0)
		{
			*i += 1;
			return (set_precision(args, src, i, NULL));
		}
		pre[2] = ft_max(0, 0, pre[2]);
		*i += 2;
		return (set_precision(args, src, i, pre));
	}
	pre[2] = ft_atoi(src + *i + 1);
	*i += 1;
	while (src[*i] <= '9' && src[*i] >= '0')
		*i += 1;
	return (set_precision(args, src, i, pre));
}

int		solve_num_point_num_neg(char *to_print, int *pre, int res)
{
	if (pre[0] >= (int)ft_strlen(++to_print) &&
		pre[2] >= (int)ft_strlen(to_print))
	{
		res = ft_max(--pre[0], pre[2], 0);
		while (pre[0]-- > pre[2])
			write(1, " ", 1);
		write(1, "-", 1);
		while (pre[2]-- > (int)ft_strlen(to_print))
			write(1, "0", 1);
	}
	else
		res = solve_num_point_num_neg2(to_print, pre, res);
	write(1, to_print, ft_strlen(to_print));
	return (res + 1);
}

int		solve_num_point_num_neg2(char *to_print, int *pre, int res)
{
	if (pre[0] > (int)ft_strlen(to_print))
	{
		res = pre[0] - 1;
		while (--pre[0] > (int)ft_strlen(to_print))
			write(1, " ", 1);
		write(1, "-", 1);
	}
	else
	{
		write(1, "-", 1);
		if (pre[2] > (int)ft_strlen(to_print))
		{
			res = pre[2];
			while (pre[2]-- > (int)ft_strlen(to_print))
				write(1, "0", 1);
		}
		else
			res = ft_strlen(to_print);
	}
	return (res);
}

int		solve_num_point_num_cero(int *pre)
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
		res = pre[0];
		while (res-- > pre[2])
			write(1, " ", 1);
		while (res-- >= 0)
			write(1, "0", 1);
		return (pre[0]);
	}
	res = pre[2];
	while (res-- > 0)
		write(1, "0", 1);
	return (pre[2]);
}
