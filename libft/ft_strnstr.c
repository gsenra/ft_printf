/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:11:21 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/05 14:38:34 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *little, size_t len)
{
	size_t		i;
	size_t		c;

	if (!(*little))
		return ((char*)str);
	i = 0;
	while (str[i] != '\0' && len > i)
	{
		if (str[i] == little[0])
		{
			c = 1;
			while (str[i + c] == little[c] && little[c] != '\0' &&
					(i + c) < len)
				c++;
			if (little[c] == '\0')
			{
				str = &str[i];
				return ((char*)str);
			}
		}
		i++;
	}
	return (0);
}
