/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:35:43 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_base(unsigned long int i, char *base, int *res, char *to_print)
{
	unsigned long int	base_length;

	base_length = ft_strlen(base);
	if (i >= base_length)
	{
		ft_base(i / base_length, base, res, to_print);
		ft_base(i % base_length, base, res, to_print);
	}
	else
	{
		to_print[*res] = base[i];
		*res = *res + 1;
	}
}

char	*ft_itoaus(unsigned int n)
{
	int				digitos;
	unsigned int	nb;
	char			*res;

	nb = n;
	digitos = 1;
	while (nb > 9 && digitos++ != 0)
		nb /= 10;
	if (!(res = (char *)malloc(sizeof(char) * (digitos) + 1)))
		return (0);
	res[digitos] = '\0';
	digitos--;
	nb = n;
	while (digitos >= 0)
	{
		res[digitos] = (char)(nb % 10 + '0');
		nb /= 10;
		digitos--;
	}
	return (res);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int		ft_max(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	return (c);
}
