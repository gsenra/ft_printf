/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:29:55 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/03 13:16:51 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dst2;
	char *src2;

	if (dst == src)
		return (dst);
	if (dst < src)
	{
		dst = ft_memcpy(dst, src, len);
		return (dst);
	}
	dst2 = (char *)dst;
	src2 = (char *)src;
	while (len-- > 0)
	{
		dst2[len] = src2[len];
	}
	return (dst);
}
