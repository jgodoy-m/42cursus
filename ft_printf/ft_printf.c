/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:34:40 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *src, ...)
{
	va_list	args;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(args, src);
	while (src[i])
	{
		if (src[i] == '%')
			res += get_flag(src, args, &i);
		else
		{
			write(1, &src[i], 1);
			res++;
		}
		if (src[i])
			i++;
	}
	va_end(args);
	return (res);
}

int		get_flag(const char *src, va_list args, int *i)
{
	*i += 1;
	if ((src[*i] == 'c') || (src[*i] == 's') || (src[*i] == 'p')
		|| (src[*i] == 'i') || (src[*i] == 'd')
		|| (src[*i] == 'u') || (src[*i] == 'x')
		|| (src[*i] == 'X') || (src[*i] == '%'))
		return (set_precision(args, src, i, NULL));
	if (src[*i] == '*')
		return (star_flag(args, src, i));
	if (src[*i] == '-')
		return (minus_flag(args, src, i));
	if ((src[*i] >= '0' && src[*i] <= '9'))
		return (number_flag(args, src, i));
	if (src[*i] == '.')
		return (point_flag(args, src, i, 0));
	return (0);
}

int		set_precision(va_list args, const char *src, int *i, int *pre)
{
	if (src[*i] == 'c')
		return (c_flag(args, pre));
	if (src[*i] == 's')
		return (s_flag(args, pre));
	if (src[*i] == 'p')
		return (p_flag(args, pre));
	if (src[*i] == 'i')
		return (i_flag(args, pre));
	if (src[*i] == 'd')
		return (d_flag(args, pre));
	if (src[*i] == 'u')
		return (u_flag(args, pre));
	if (src[*i] == 'x')
		return (x_flag(args, pre));
	if (src[*i] == 'X')
		return (xx_flag(args, pre));
	if (src[*i] == '%')
		return (per_flag(pre));
	return (0);
}
