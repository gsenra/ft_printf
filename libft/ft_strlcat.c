/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:02:18 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/05 10:42:25 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** TAMANHO DEST
** TAMANHO SRC
** SE DEST COMPORTA O TANTO QUE QUERO COPIAR => R= TAM SRC + ESSE TANTO
** R= TAM SRC + TAM DEST
** COPIAR A SRC P/ DEST ENQUANTO ELA EXISTIR E O SIZE PEDIR
*/
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	tdest;
	size_t	tsrc;
	size_t	i;
	size_t	c;

	tdest = ft_strlen(dest);
	tsrc = ft_strlen(src);
	if (tdest >= size)
		return (tsrc + size);
	i = 0;
	c = tdest;
	while (src[i] != '\0' && c < (size - 1) && size != '\0')
	{
		dest[c] = (char)src[i];
		c++;
		i++;
	}
	dest[c] = '\0';
	return (tsrc + tdest);
}
