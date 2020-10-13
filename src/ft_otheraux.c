/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otheraux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 17:08:07 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/09 17:56:59 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static int		ft_tam_base_hex(unsigned n, unsigned int base)
{
	unsigned int	len;

	len = 0;
	while (n >= base)
	{
		n /= base;
		++len;
	}
	return (len + 1);
}

unsigned char	*ft_itoa_hex(unsigned int n, unsigned int base)
{
	unsigned char	*str;
	unsigned int	tam;

	tam = ft_tam_base_hex(n, base);
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char) * (tam + 1))))
		return (0);
	str[tam] = '\0';
	tam = tam - 1;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[tam--] = (n % base < 10 ? n % base + 48 : n % base + 87);
		n = n / base;
	}
	return (str);
}

unsigned char	*ft_ajustprt(unsigned char *temp, t_int *list)
{
	unsigned char	*is;
	int				n;

	if (list->yepprec == 1 && list->prec == 0)
	{
		if (!(is = (unsigned char *)malloc(sizeof(char) + 3)))
			return (0);
		is[2] = '\0';
	}
	else
	{
		n = ft_strlen_uns(temp) + 3;
		if (!(is = (unsigned char*)malloc(sizeof(char) * n)))
			return (0);
		n = 0;
		while (temp[n])
		{
			is[2 + n] = temp[n];
			n++;
		}
		is[2 + n] = '\0';
	}
	is[0] = '0';
	is[1] = 'x';
	return (is);
}
