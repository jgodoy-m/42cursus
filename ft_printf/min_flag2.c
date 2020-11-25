/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_flag2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:35:04 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		set_min_star(va_list args, const char *src, int *i)
{
	int	input;
	int	pre[3];

	*i += 1;
	input = (int)va_arg(args, int);
	pre[0] = ft_abs(input) * -1;
	if ((src[*i] == 'c') || (src[*i] == 's') || (src[*i] == 'p') ||
		(src[*i] == 'i') || (src[*i] == 'd') || (src[*i] == 'u') ||
		(src[*i] == 'x') || (src[*i] == 'X') || (src[*i] == '%'))
	{
		pre[1] = 0;
		return (set_precision(args, src, i, pre));
	}
	if (src[*i] == '.')
		return (set_min_star_point(args, src, i, pre));
	return (0);
}
