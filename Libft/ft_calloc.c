/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgodoy-m <jgodoy-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:17:41 by jgodoy-m          #+#    #+#             */
/*   Updated: 2019/11/13 20:47:39 by jgodoy-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = -1;
	p = (char*)malloc(count * size);
	if (p == NULL)
		return (NULL);
	while (++i < count * size)
	{
		p[i] = '\0';
	}
	return (p);
}
