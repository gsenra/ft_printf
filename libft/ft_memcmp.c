/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 09:26:55 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/03 13:21:42 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cmps1;
	unsigned char	*cmps2;

	cmps1 = (unsigned char*)s1;
	cmps2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (*cmps1 != *cmps2)
			return ((int)(*cmps1 - *cmps2));
		n--;
		cmps1++;
		cmps2++;
	}
	return (0);
}
