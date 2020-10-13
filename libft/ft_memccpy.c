/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:51:21 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/03 13:14:03 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ccpysrc;
	char	*ccpydst;
	size_t	i;
	char	*pt;

	ccpysrc = (char*)src;
	ccpydst = (char*)dst;
	i = 0;
	pt = 0;
	while (i < n && pt == 0)
	{
		ccpydst[i] = ccpysrc[i];
		if (ccpysrc[i] == (char)c && n != 0)
			pt = ccpydst + i + 1;
		i++;
	}
	return (pt);
}
