/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:26:08 by jgodoy-m          #+#    #+#             */
/*   Updated: 2019/11/07 20:19:56 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = 0;
	while ((*aux_s1 != '\0' && *aux_s2 != '\0') && *aux_s1 == *aux_s2)
	{
		aux_s1++;
		aux_s2++;
	}
	if (aux_s1[i] == aux_s2[i])
	{
		return (0);
	}
	else
	{
		return (*aux_s1 - *aux_s2);
	}
}
