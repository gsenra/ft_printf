/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:36:36 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static void			ft_isnum(const char *str, t_int *list, int x)
{
	int		i;
	int		f;
	char	*numb;

	i = list->i - x;
	if (!(numb = (char *)malloc(sizeof(char) * (x + 1))))
		return ;
	f = 0;
	while (f < x)
	{
		numb[f] = str[i + f];
		f++;
	}
	numb[f] = '\0';
	list->prec = ft_atoi(numb);
	free(numb);
}

static void			ft_isvalor(const char *str, t_int *list)
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
}

void				ft_isprec(const char *str, t_int *list)
{
	list->yepprec = 1;
	if (str[list->i] >= '0' && str[list->i] <= '9')
		ft_isvalor(str, list);
	else if (str[list->i] == '*')
	{
		list->prec = va_arg(list->args, int);
		list->i = list->i + 1;
	}
	else
		list->prec = 0;
	if (list->prec < 0)
	{
		list->yepprec = 0;
		list->prec = 0;
	}
}
