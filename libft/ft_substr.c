/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 01:49:27 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/05 10:55:24 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;

	if (!(s))
		return (0);
	if (start > ((unsigned int)ft_strlen((char*)s)))
	{
		ans = (char *)malloc(1);
		if (!(ans))
			return (0);
		*ans = '\0';
		return (ans);
	}
	if (!(ans = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		ans[i] = (char)s[start];
		i++;
		start++;
	}
	ans[i] = '\0';
	return (ans);
}
