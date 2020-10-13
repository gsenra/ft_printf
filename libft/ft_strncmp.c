/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:34:15 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *cmps1;
	unsigned char *cmps2;

	cmps1 = (unsigned char*)s1;
	cmps2 = (unsigned char*)s2;
	while ((*cmps1 == *cmps2 && n != 0 && *cmps1 != '\0') &&
			(*cmps2 != '\0'))
	{
		n--;
		cmps1++;
		cmps2++;
	}
	if (*cmps1 != *cmps2 && n != 0)
		return ((int)*cmps1 - *cmps2);
	return (0);
}

int		ft_strncmp_uns(unsigned char *s1, const char *s2, size_t n)
{
	unsigned char *cmps1;
	unsigned char *cmps2;

	cmps1 = (unsigned char*)s1;
	cmps2 = (unsigned char*)s2;
	while ((*cmps1 == *cmps2 && n != 0 && *cmps1 != '\0') &&
			(*cmps2 != '\0'))
	{
		n--;
		cmps1++;
		cmps2++;
	}
	if (*cmps1 != *cmps2 && n != 0)
		return ((int)*cmps1 - *cmps2);
	return (0);
}
