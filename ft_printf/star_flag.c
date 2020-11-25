/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:36:04 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		star_flag(va_list args, const char *src, int *i)
{
	int	pre[3];

	*i += 1;
	pre[0] = (int)va_arg(args, int);
	if ((src[*i] == 'c') || (src[*i] == 's') || (src[*i] == 'p') ||
		(src[*i] == 'i') || (src[*i] == 'd') || (src[*i] == 'u') ||
		(src[*i] == 'x') || (src[*i] == 'X') || (src[*i] == '%'))
	{
		pre[1] = 0;
		return (set_precision(args, src, i, pre));
	}
	if (src[*i] == '.')
		return (set_star_point(args, src, i, pre));
	return (0);
}

int		set_star_point(va_list args, const char *src, int *i, int *pre)
{
	*i += 1;
	if ((src[*i] == 'c') || (src[*i] == 's') || (src[*i] == 'p') ||
		(src[*i] == 'i') || (src[*i] == 'd') || (src[*i] == 'u') ||
		(src[*i] == 'x') || (src[*i] == 'X') || (src[*i] == '%'))
	{
		pre[1] = 0;
		return (set_precision(args, src, i, pre));
	}
	if (src[*i] == '*')
		return (set_star_point_star(args, src, i, pre));
	if (src[*i] <= '9' && src[*i] >= '0')
	{
		pre[2] = ft_atoi(src + *i);
		pre[1] = 3;
		while (src[*i] <= '9' && src[*i] >= '0')
			*i += 1;
		return (set_precision(args, src, i, pre));
	}
	return (0);
}

int		set_star_point_star(va_list args, const char *src, int *i, int *pre)
{
	int	input;

	input = (int)va_arg(args, int);
	if (input < 0)
	{
		*i += 1;
		return (set_precision(args, src, i, NULL));
	}
	pre[2] = ft_max(0, 0, input);
	if (pre[0] < 0)
	{
		pre[0] *= -1;
		pre[1] = 7;
	}
	else
		pre[1] = 3;
	*i += 1;
	return (set_precision(args, src, i, pre));
}
