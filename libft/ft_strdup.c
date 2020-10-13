/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:51:52 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/06/09 18:21:50 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *src)
{
	char	*ans;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(ans = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		ans[i] = src[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

unsigned char	*ft_strdup_uns(unsigned char *is)
{
	unsigned char	*ans;
	int				i;

	i = ft_strlen_uns(is);
	if (!(ans = (unsigned char*)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (is[i] != '\0')
	{
		ans[i] = is[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
