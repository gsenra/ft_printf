/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printother.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 12:31:59 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/06/09 18:15:50 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	ft_isunint(unsigned char *is, t_int *list)
{
	int				x;
	unsigned char	*lans;

	if (ft_strncmp_uns(is, "0", 3) == 0 &&
	list->yepprec == 1 && list->prec == 0)
	{
		free(is);
		is = (unsigned char*)malloc(sizeof(char) * 1);
		is[0] = '\0';
		list->yepprec = 0;
		list->zero = 0;
	}
	lans = ft_unsflags(is, list);
	x = 0;
	while (lans[x] != '\0')
	{
		write(1, &lans[x], 1);
		x++;
		list->size = list->size + 1;
	}
	list->i = list->i + 1;
	free(lans);
	ft_restarter(list);
}

void	ft_isptr(unsigned char *is, t_int *list)
{
	int				x;
	unsigned char	*lans;

	if (ft_strncmp_uns(is, "", 3) == 0 && list->yepprec == 1 &&
	list->prec == 0)
	{
		free(is);
		is = (unsigned char*)malloc(sizeof(char) * 1);
		is[0] = '0';
		list->yepprec = 0;
		list->zero = 0;
	}
	lans = ft_ptrflags(is, list);
	x = 0;
	while (lans[x] != '\0')
	{
		write(1, &lans[x], 1);
		x++;
		list->size = list->size + 1;
	}
	list->i = list->i + 1;
	free(lans);
	ft_restarter(list);
}

void	ft_ishex(unsigned char *is, t_int *list, const char *str)
{
	int				x;
	unsigned char	*lans;

	if (ft_strncmp_uns(is, "0", 3) == 0 && list->yepprec == 1 &&
	list->prec == 0)
	{
		free(is);
		is = (unsigned char*)malloc(sizeof(char) * 1);
		is[0] = '\0';
		list->yepprec = 0;
		list->zero = 0;
	}
	lans = ft_hexflags(is, list);
	x = 0;
	while (lans[x] != '\0')
	{
		if (str[list->i] == 'X' && lans[x] >= 'a' && lans[x] <= 'f')
			lans[x] = lans[x] - 32;
		write(1, &lans[x], 1);
		x++;
	}
	list->size = list->size + x;
	list->i = list->i + 1;
	free(lans);
	ft_restarter(list);
}
