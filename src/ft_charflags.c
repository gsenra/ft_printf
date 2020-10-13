/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 15:51:52 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/09 17:38:18 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static void		ft_printlans(t_int *list)
{
	char	lans;
	int		i;

	i = list->larg - 1;
	lans = (list->zero == 1 ? '0' : ' ');
	while (i > 0)
	{
		write(1, &lans, 1);
		list->size = list->size + 1;
		i--;
	}
}

static void		ft_printc(char c, t_int *list)
{
	write(1, &c, 1);
	list->size = list->size + 1;
}

void			ft_charflags(char c, t_int *list)
{
	list->prec = 0;
	if (list->larg > 0)
	{
		if (list->dash == 0)
		{
			ft_printlans(list);
			ft_printc(c, list);
		}
		if (list->dash == 1)
		{
			ft_printc(c, list);
			ft_printlans(list);
		}
	}
	else
		ft_printc(c, list);
}
