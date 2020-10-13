/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbasics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:20:06 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/09 18:10:44 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void			ft_ischar(char c, t_int *list)
{
	ft_charflags(c, list);
	list->i = list->i + 1;
	ft_restarter(list);
}

void			ft_isint(char *is, t_int *list)
{
	int		x;
	char	*print;

	if ((ft_strncmp(is, "0", 3) == 0) && list->yepprec == 1 && list->prec == 0)
	{
		free(is);
		is = (char*)malloc(sizeof(char) * 1);
		is[0] = '\0';
		list->yepprec = 0;
		list->zero = 0;
	}
	print = ft_intflags(is, list);
	x = 0;
	while (print[x] != '\0')
	{
		write(1, &print[x], 1);
		list->size = list->size + 1;
		x++;
	}
	list->i = list->i + 1;
	free(print);
	ft_restarter(list);
}

static void		ft_printis(char *lans, t_int *list)
{
	int		x;

	x = 0;
	while (lans[x] != '\0')
	{
		write(1, &lans[x], 1);
		x++;
		list->size = list->size + 1;
	}
}

void			ft_isstr(char *is, t_int *list)
{
	char	*lans;
	char	*ans;

	if (!is)
	{
		if (!(ans = (char*)malloc(sizeof(char) * 6)))
			return ;
		ft_memcpy(ans, "(null)", 6);
	}
	else if (ft_strncmp(is, "", 3) == 0)
	{
		if (!(ans = (char*)malloc(sizeof(char) * 1)))
			return ;
		ans[0] = '\0';
	}
	else
		ans = ft_strdup(is);
	lans = ft_strflags(ans, list);
	ft_printis(lans, list);
	list->i = list->i + 1;
	free(ans);
	free(lans);
	ft_restarter(list);
}
