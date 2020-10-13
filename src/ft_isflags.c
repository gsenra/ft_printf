/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:13:36 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static void		ft_isnum(const char *str, t_int *list, int x)
{
	int		i;
	int		f;
	char	*numb;

	i = list->i - x;
	if (!(numb = (char*)malloc(sizeof(char) * (x + 1))))
		return ;
	f = 0;
	while (f < x)
	{
		numb[f] = str[i + f];
		f++;
	}
	numb[f] = '\0';
	list->larg = ft_atoi(numb);
	free(numb);
}

static void		ft_isvalor(const char *str, t_int *list)
{
	int x;

	x = 0;
	while (str[list->i] >= '0' && str[list->i] <= '9')
	{
		x++;
		list->i = list->i + 1;
	}
	if (x > 0)
		ft_isnum(str, list, x);
	if (str[list->i] == '*')
	{
		list->larg = va_arg(list->args, int);
		list->i = list->i + 1;
	}
	if (list->larg < 0)
	{
		list->larg = list->larg * -1;
		list->dash = 1;
		list->zero = 0;
	}
}

static void		ft_nornflags(const char *str, t_int *list)
{
	if ((str[list->i] >= '0' && str[list->i] <= '9') || str[list->i] == '*')
	{
		ft_isvalor(str, list);
		ft_isflags(str, list);
	}
	if (str[list->i] == '\0')
	{
		list->null = 1;
		while (ft_torf(str, list) != 1)
			list->i = list->i + 1;
		list->i = list->i + 1;
		return ;
	}
	if (ft_torf(str, list) != 1 && list->null == 0)
	{
		list->i = list->i + 1;
		ft_isflags(str, list);
	}
}

void			ft_isflags(const char *str, t_int *list)
{
	if (str[list->i] == '.')
	{
		list->i = list->i + 1;
		ft_isprec(str, list);
		ft_isflags(str, list);
	}
	if (str[list->i] == '0' &&
	(str[list->i - 1] == ' ' || str[list->i - 1] == '%'))
	{
		list->i = list->i + 1;
		list->zero = 1;
		list->dash = 0;
		ft_isflags(str, list);
	}
	if (str[list->i] == '-')
	{
		list->i = list->i + 1;
		list->zero = 0;
		list->dash = 1;
		ft_isflags(str, list);
	}
	ft_nornflags(str, list);
}
