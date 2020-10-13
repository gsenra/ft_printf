/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:46:24 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/05/29 17:30:52 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cps;

	cps = (unsigned char*)s;
	if (n != '\0')
	{
		while (n != 0)
		{
			if (*cps++ == (unsigned char)c)
				return ((void*)(cps - 1));
			n--;
		}
	}
	return (0);
}
