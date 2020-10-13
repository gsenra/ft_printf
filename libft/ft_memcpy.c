/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:59:42 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/03 15:25:31 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*cpystr2;
	char	*cpystr1;

	cpystr2 = (char*)str2;
	cpystr1 = (char*)str1;
	i = 0;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	while (i < n)
	{
		cpystr1[i] = cpystr2[i];
		i++;
	}
	return (cpystr1);
}
