/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 03:20:05 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/05 14:53:12 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		c;
	size_t	sz;

	if (!(s1) || !(s2))
		return (0);
	sz = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (sz + 1))))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	c = 0;
	while (s2[c] != '\0')
	{
		str[i] = s2[c];
		i++;
		c++;
	}
	str[i] = '\0';
	return (str);
}
