/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:32:01 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/06/09 17:28:04 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int				ft_tamanho(unsigned int num)
{
	int	tam;

	tam = 1;
	while (num >= 10)
	{
		tam++;
		num = num / 10;
	}
	return (tam);
}

char			*ft_itoa(int n)
{
	unsigned int	num;
	int				tam;
	char			*ans;

	if (n < 0)
		num = (unsigned int)(n * -1);
	if (n >= 0)
		num = (unsigned int)n;
	tam = ft_tamanho(num) + 1 + ((n < 0) ? 1 : 0);
	if (!(ans = (char*)malloc(sizeof(char) * (tam))))
		return (0);
	if (n < 0)
		ans[0] = '-';
	ans[tam - 1] = '\0';
	tam = tam - 2;
	while (num >= 10)
	{
		ans[tam] = (char)(num % 10) + '0';
		num = num / 10;
		tam--;
	}
	ans[tam] = (char)num % 10 + '0';
	return (ans);
}

unsigned char	*ft_itoa_best(unsigned int n)
{
	int				tam;
	unsigned char	*ans;

	tam = ft_tamanho(n) + 1;
	if (!(ans = (unsigned char*)malloc(sizeof(char) * (tam + 1))))
		return (0);
	ans[tam - 1] = '\0';
	tam = tam - 2;
	while (n >= 10)
	{
		ans[tam] = (char)(n % 10) + '0';
		n = n / 10;
		tam--;
	}
	ans[tam] = (char)n % 10 + '0';
	return (ans);
}

static int		ft_tam_base_ptr(uintptr_t n, unsigned int base)
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

unsigned char	*ft_itoa_ultra(uintptr_t n, unsigned int base)
{
	unsigned char	*str;
	unsigned int	tam;

	tam = ft_tam_base_ptr(n, base);
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
