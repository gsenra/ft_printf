/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 13:14:45 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/09 18:14:18 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static void		ft_convtorf(const char *str, t_int *list)
{
	int i;

	i = list->i;
	while ((str[i] != 'c' && str[i] != 's' && str[i] != 'd' && str[i] != 'i' &&
	str[i] != '%' && str[i] != 'x' && str[i] != 'X' && str[i] != 'u' &&
	str[i] != 'p') && str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') ||
		(str[i] >= 'A' && str[i] <= 'Z'))
			break ;
		i++;
	}
	if (str[i] && ft_othertorf(str, i) != 1)
		list->i = list->i + 1;
	else if (str[i] && ft_othertorf(str, i) != 0)
	{
		list->yepconv = 1;
		ft_ispercent(str, list);
	}
	else if (!(str[i]))
	{
		if (str[i] == '\0')
			list->null = 1;
		list->i = list->i + i;
	}
}

void			ft_restarter(t_int *list)
{
	list->zero = 0;
	list->larg = 0;
	list->prec = 0;
	list->dash = 0;
	list->yepprec = 0;
	list->neg = 0;
	list->null = 0;
	list->yepconv = 0;
}

static void		ft_starter(t_int *list)
{
	list->i = 0;
	list->size = 0;
	list->zero = 0;
	list->larg = 0;
	list->prec = 0;
	list->dash = 0;
	list->yepprec = 0;
	list->neg = 0;
	list->null = 0;
	list->yepconv = 0;
}

int				ft_printf(const char *str, ...)
{
	t_int	list;

	va_start(list.args, str);
	ft_starter(&list);
	while (str[list.i])
	{
		if (str[list.i] != '%')
		{
			write(1, &str[list.i], 1);
			list.i++;
			list.size++;
		}
		if (str[list.i] == '%')
		{
			list.i++;
			ft_convtorf(str, &list);
			if (list.null == 1)
				break ;
		}
	}
	va_end(list.args);
	return (list.size);
}
