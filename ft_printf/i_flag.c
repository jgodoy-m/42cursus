/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:34:46 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		i_flag(va_list args, int *pre)
{
	int		input;
	char	*to_print;
	int		res;

	input = (int)va_arg(args, int);
	to_print = ft_itoa(input);
	if (pre)
		res = solve_int_precision(to_print, pre);
	else
		res = write(1, to_print, ft_strlen(to_print));
	free(to_print);
	return (res);
}

int		d_flag(va_list args, int *pre)
{
	int		input;
	char	*to_print;
	int		res;

	input = (int)va_arg(args, int);
	to_print = ft_itoa(input);
	if (pre)
		res = solve_int_precision(to_print, pre);
	else
		res = write(1, to_print, ft_strlen(to_print));
	free(to_print);
	return (res);
}

int		number_flag(va_list args, const char *src, int *i)
{
	int	pre[3];

	pre[1] = 0;
	while (src[*i] == '0')
	{
		pre[1] = 1;
		*i += 1;
	}
	if (src[*i] == '*' && src[*i - 1] == '0')
	{
		pre[0] = (int)va_arg(args, int);
		*i += 1;
	}
	else
		pre[0] = ft_atoi(src + *i);
	if (src[*i] == '-')
		return (minus_flag(args, src, i));
	while (src[*i] >= '0' && src[*i] <= '9')
		*i += 1;
	if (src[*i] == '.')
		return (set_num_point_num(args, src, i, pre));
	return (set_precision(args, src, i, pre));
}
