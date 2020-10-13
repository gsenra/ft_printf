/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:21:33 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/01/24 20:02:37 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *swp;

	swp = (unsigned char*)str;
	while (n > 0)
	{
		*(swp++) = (unsigned char)c;
		n--;
	}
	return (str);
}
