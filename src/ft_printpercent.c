/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 13:30:00 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char		*ft_dashfalse(char *ans, t_int *list)
{
	int		i;
	int		j;
	char	*lans;

	if (!(lans = (char*)malloc(sizeof(char) * (list->larg + 1))))
		return (0);
	i = 0;
	while (i < (list->larg - list->prec - 1))
	{
		lans[i] = (list->zero == 1 ? '0' : ' ');
		i++;
	}
	j = 0;
	while ((i + j) < list->larg)
	{
		lans[i + j] = ans[j];
		j++;
	}
	lans[i + j] = '\0';
	return (lans);
}

static char		*ft_dashtrue(char *ans, t_int *list)
{
	int		i;
	char	*lans;

	if (!(lans = (char*)malloc(sizeof(char) * (list->larg + 1))))
		return (0);
	i = 0;
	while (ans[i] != '\0')
	{
		lans[i] = ans[i];
		i++;
	}
	while (i < list->larg)
	{
		lans[i] = (list->zero == 1 ? '0' : ' ');
		i++;
	}
	lans[i] = '\0';
	return (lans);
}

static char		*ft_flagspercent(t_int *list)
{
	char	*ans;
	char	*lans;

	list->prec = 0;
	if (!((ans = (char*)malloc(sizeof(char) * 2))))
		return (0);
	ans[0] = '%';
	ans[1] = '\0';
	if (list->larg > 1 && list->larg > list->prec)
	{
		if (list->dash == 0)
			lans = ft_dashfalse(ans, list);
		if (list->dash == 1)
			lans = ft_dashtrue(ans, list);
	}
	else
		lans = ft_strdup(ans);
	free(ans);
	return (lans);
}

void			ft_printpercent(t_int *list)
{
	int		i;
	char	*lans;

	i = 0;
	lans = ft_flagspercent(list);
	while (lans[i])
	{
		write(1, &lans[i], 1);
		i++;
		list->size = list->size + 1;
	}
	list->i = list->i + 1;
	free(lans);
	ft_restarter(list);
}
