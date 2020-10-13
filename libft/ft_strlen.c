/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 09:53:44 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/06/09 18:21:08 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned int size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

int		ft_strlen_uns(unsigned char *is)
{
	int i;

	i = 0;
	while (is[i])
		i++;
	return (i);
}
