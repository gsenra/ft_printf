/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 03:37:41 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/03 18:16:23 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t in;
	size_t fim;

	if (s1 == NULL || set == NULL)
		return (0);
	in = 0;
	while (s1[in] && ft_strchr(set, s1[in]) != NULL)
		in++;
	fim = ft_strlen(&s1[in]);
	if (fim != 0)
	{
		while ((s1[in + fim - 1]) &&
				(ft_strrchr(set, s1[in + fim - 1]) != NULL))
			fim--;
	}
	return (ft_substr(s1, in, fim));
}
