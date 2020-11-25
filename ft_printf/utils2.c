/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:05:07 by jgodoy-m          #+#    #+#             */
/*   Updated: 2020/11/16 15:35:59 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoi(const char *str)
{
	int				pos;
	int				neg;
	unsigned int	res;

	pos = 0;
	neg = 1;
	res = 0;
	while ((str[pos] == ' ') || (str[pos] == '\n') || (str[pos] == '\t')
			|| (str[pos] == '\v') || (str[pos] == '\f') || (str[pos] == '\r'))
		pos++;
	if (str[pos] == '-' || str[pos] == '+')
		if (str[pos++] == '-')
			neg = -1;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		if ((res == 214748364 && str[pos] > '7' && neg % 2 == 0)
				|| (res > 214748364 && neg == 1))
			return (-1);
		if ((res == 214748364 && str[pos] > '8' && neg % 2 != 0)
		|| (res > 214748364 && neg == -1))
			return (0);
		res = res * 10 + (str[pos++] - 48);
	}
	return (res * neg);
}

char	*ft_itoa(int n)
{
	int				digitos;
	unsigned int	nb;
	char			*res;
	int				sig;

	digitos = 1;
	sig = (n < 0) ? (1) : (0);
	nb = (n < 0) ? (-n) : (n);
	while (nb > 9 && digitos++ != 0)
		nb /= 10;
	if (!(res = (char *)malloc(sizeof(char) * (digitos) + 1 + sig)))
		return (0);
	res[digitos + sig] = '\0';
	if (sig > 0)
		res[0] = '-';
	nb = (n < 0) ? (-n) : (n);
	digitos--;
	while (digitos >= 0)
	{
		res[digitos + sig] = (char)(nb % 10 + '0');
		nb /= 10;
		digitos--;
	}
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
		pos++;
	return (pos);
}
