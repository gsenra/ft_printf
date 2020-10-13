/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:07:39 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/05/29 17:30:52 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	*c;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	c = malloc(num * size);
	if (c)
		ft_bzero(c, num * size);
	return ((void*)c);
}
