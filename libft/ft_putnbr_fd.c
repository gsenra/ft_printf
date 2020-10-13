/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:54:33 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/05 10:45:43 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_up_putnbr(unsigned int n, int fd)
{
	char		num;

	if (n / 10 > 0)
		ft_up_putnbr(n / 10, fd);
	num = n % 10 + '0';
	ft_putchar_fd(num, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = n * -1;
	}
	else
		nb = n;
	ft_up_putnbr(nb, fd);
}
