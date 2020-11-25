/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:34:17 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	c_flag(va_list args, int *pre)
{
	char	to_print[2];

	to_print[0] = (unsigned char)va_arg(args, int);
	if (!pre)
		return (write(1, to_print, 1));
	to_print[1] = '\0';
	if (to_print[0] == 0)
	{
		if (pre[0] > 0)
			pre[0]--;
		if (pre[0] < 0)
			pre[0]++;
		return (solve_char_precision(to_print, pre) + 1);
	}
	return (solve_str_precision(to_print, pre));
}

int	solve_char_precision(char *to_print, int *pre)
{
	int	res;

	res = 0;
	while (pre[0] > 0 && pre[0] > (int)ft_strlen(to_print))
	{
		write(1, " ", 1);
		res++;
		pre[0]--;
	}
	write(1, to_print, ft_max(1, 1, ft_strlen(to_print)));
	while (pre[0] < 0 && (pre[0] * -1) > (int)ft_strlen(to_print))
	{
		write(1, " ", 1);
		res++;
		pre[0]++;
	}
	return (res + ft_strlen(to_print));
}
