/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_torfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:52:30 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int		ft_othertorf(const char *str, int i)
{
	if (str[i] == 'c' || str[i] == 's' ||
	str[i] == 'd' || str[i] == 'i' ||
	str[i] == '%' || str[i] == 'x' ||
	str[i] == 'X' || str[i] == 'u' ||
	str[i] == 'p')
		return (1);
	return (0);
}

int		ft_torfplus(const char *str, t_int *list)
{
	if (str[list->i] == 'c' || str[list->i] == 's' ||
	str[list->i] == 'd' || str[list->i] == 'i' ||
	str[list->i] == '%' || str[list->i] == 'x' ||
	str[list->i] == 'X' || str[list->i] == 'u' ||
	str[list->i] == 'p' || str[list->i] == '-' ||
	str[list->i] == '0' || str[list->i] == '*' ||
	str[list->i] == '.' || (str[list->i] >= '1' &&
	str[list->i] <= '9'))
		return (1);
	return (0);
}

int		ft_torf(const char *str, t_int *list)
{
	if (str[list->i] == 'c' || str[list->i] == 's' ||
	str[list->i] == 'd' || str[list->i] == 'i' ||
	str[list->i] == '%' || str[list->i] == 'x' ||
	str[list->i] == 'X' || str[list->i] == 'u' ||
	str[list->i] == 'p')
		return (1);
	return (0);
}
