/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uxper_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:35:55 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		u_flag(va_list args, int *pre)
{
	unsigned int	input;
	char			*to_print;
	int				res;

	input = (unsigned int)va_arg(args, unsigned int);
	to_print = ft_itoaus(input);
	if (pre)
		res = solve_int_precision(to_print, pre);
	else
		res = write(1, to_print, ft_strlen(to_print));
	free(to_print);
	return (res);
}

int		x_flag(va_list args, int *pre)
{
	unsigned int	input;
	int				res[1];
	char			to_print[32];

	*res = 0;
	while (*res < 32)
		to_print[(*res)++] = 0;
	*res = 0;
	input = (unsigned int)va_arg(args, unsigned int);
	ft_base(input, "0123456789abcdef", res, to_print);
	if (pre)
		return (solve_int_precision(to_print, pre));
	return (write(1, to_print, ft_strlen(to_print)));
}

int		xx_flag(va_list args, int *pre)
{
	unsigned int	input;
	int				res[1];
	char			to_print[32];

	*res = 0;
	while (*res < 32)
		to_print[(*res)++] = 0;
	*res = 0;
	input = (unsigned int)va_arg(args, unsigned int);
	ft_base(input, "0123456789ABCDEF", res, to_print);
	if (pre)
		return (solve_int_precision(to_print, pre));
	return (write(1, to_print, ft_strlen(to_print)));
}

int		per_flag(int *pre)
{
	char	to_print[2];

	if (pre && pre[1] == 7)
	{
		pre[0] *= -1;
		pre[1] = 4;
	}
	to_print[0] = '%';
	if (!pre)
		return (write(1, to_print, 1));
	to_print[1] = '\0';
	if (pre && pre[1] != 3 && ft_abs(pre[0]) < (int)ft_strlen(to_print))
		return (write(1, to_print, ft_strlen(to_print)));
	else if (pre)
		return (solve_str_precision(to_print, pre));
	return (write(1, to_print, ft_strlen(to_print)));
}
