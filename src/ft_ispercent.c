/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispercent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:09:51 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/06/09 17:51:52 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

t_int		*ft_basic_convert(const char *str, t_int *list)
{
	char	c;
	char	*is;

	if (str[list->i] == 'c')
	{
		c = (char)va_arg(list->args, int);
		ft_ischar(c, list);
	}
	if (str[list->i] == 'i' || str[list->i] == 'd')
	{
		is = ft_itoa(va_arg(list->args, int));
		ft_isint(is, list);
	}
	if (str[list->i] == 's')
	{
		is = va_arg(list->args, char*);
		ft_isstr(is, list);
	}
	return (list);
}

t_int		*ft_other_convert(const char *str, t_int *list)
{
	unsigned char	*is;
	unsigned char	*temp;
	uintptr_t		n;

	if (str[list->i] == 'u')
	{
		is = ft_itoa_best(va_arg(list->args, unsigned int));
		ft_isunint(is, list);
	}
	if (str[list->i] == 'p')
	{
		n = va_arg(list->args, uintptr_t);
		if (!n)
			n = 0;
		temp = ft_itoa_ultra(n, 16);
		is = ft_ajustprt(temp, list);
		free(temp);
		ft_isptr(is, list);
	}
	if (str[list->i] == 'x' || str[list->i] == 'X')
	{
		is = ft_itoa_hex(va_arg(list->args, unsigned int), 16);
		ft_ishex(is, list, str);
	}
	return (list);
}

t_int		*ft_ispercent(const char *str, t_int *list)
{
	if (ft_torfplus(str, list) != 0)
	{
		if ((str[list->i] == '-' || str[list->i] == '0' || str[list->i] == '*'
		|| str[list->i] == '.' || (str[list->i] >= '1' && str[list->i] <= '9'))
		&& list->yepconv == 1)
			ft_isflags(str, list);
		if ((str[list->i] == 's' || str[list->i] == 'c' || str[list->i] == 'd'
		|| str[list->i] == 'i') && list->yepconv == 1)
			ft_basic_convert(str, list);
		if ((str[list->i] == '%') && list->yepconv == 1)
			ft_printpercent(list);
		if ((str[list->i] == 'u' || str[list->i] == 'p' || str[list->i] == 'x'
		|| str[list->i] == 'X') && list->yepconv == 1)
			ft_other_convert(str, list);
	}
	else
	{
		list->i = list->i + 1;
		ft_ispercent(str, list);
	}
	return (list);
}
