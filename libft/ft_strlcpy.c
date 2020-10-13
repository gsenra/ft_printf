/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 10:22:59 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/05 13:46:45 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t c;

	if (!(src) || !(dest))
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(src);
	if (i > size)
		i = size - 1;
	dest[i] = '\0';
	c = 0;
	if (src[0] != '\0')
	{
		while (--i > 0 && dest)
		{
			dest[i] = (char)src[i];
			c++;
		}
	}
	dest[i] = (char)src[i];
	i = ft_strlen(src);
	return (i);
}
