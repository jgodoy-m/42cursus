/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:35:12 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	p_flag(va_list args, int *pre)
{
	unsigned long int	input;
	void				*aux;
	int					res[1];
	char				to_print[32];

	*res = 0;
	while (*res < 32)
		to_print[(*res)++] = 0;
	*res = 2;
	to_print[0] = '0';
	to_print[1] = 'x';
	aux = (void*)va_arg(args, void*);
	input = (unsigned long int)aux;
	ft_base(input, "0123456789abcdef", res, to_print);
	if (!pre)
		return (write(1, to_print, ft_strlen(to_print)));
	if (pre[1] == 10)
		return (write(1, "0x", 2));
	if (pre[1] == 3 && (int)ft_strlen(to_print) == 3 && to_print[2] == '0')
		to_print[2] = 0;
	return (solve_p_precision(to_print, pre));
}

int	solve_p_precision(char *to_print, int *pre)
{
	int	aux;

	if (pre[1] == 0 || (pre[1] == 3 && pre[2] == 0))
	{
		aux = pre[0];
		while (aux-- > (int)ft_strlen(to_print))
			write(1, " ", 1);
		write(1, to_print, ft_strlen(to_print));
		return (ft_max(pre[0], ft_strlen(to_print), 0));
	}
	if (pre[1] == 3)
		return (solve_p_num_point_num(to_print, pre, 0));
	if (pre[1] == 11)
	{
		write(1, "0x", 2);
		if (pre[2] == 0)
			return (2);
		aux = pre[2] + 2;
		while (pre[2]-- > (int)ft_strlen(to_print) - 2)
			write(1, "0", 1);
		write(1, to_print + 2, ft_strlen(to_print) - 2);
		return (aux);
	}
	return (solve_int_precision2(to_print, pre));
}

int	solve_p_num_point_num(char *to_print, int *pre, int res)
{
	if (pre[0] > (int)ft_strlen(to_print) && pre[2] > (int)ft_strlen(to_print))
	{
		res = ft_max(pre[0], pre[2], 0);
		while (pre[0]-- > pre[2])
			write(1, " ", 1);
		write(1, "0x", 2);
		while (pre[2]-- > (int)ft_strlen(to_print))
			write(1, "0", 1);
	}
	else if (pre[0] > (int)ft_strlen(to_print))
	{
		res = pre[0];
		while (pre[0]-- > (int)ft_strlen(to_print))
			write(1, " ", 1);
		write(1, "0x", 2);
	}
	else
	{
		res = pre[2] + 2;
		write(1, "0x", 2);
		while (pre[2]-- > (int)ft_strlen(to_print) - 2)
			write(1, "0", 1);
	}
	write(1, to_print + 2, ft_strlen(to_print) - 2);
	return (res);
}
