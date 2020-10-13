/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:44:32 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char		*largelse(t_int *list, char *lans, char *ans)
{
	int n;

	n = 0;
	while (ans[n] != '\0')
	{
		lans[n] = ans[n];
		n++;
	}
	while (n < (list->larg))
	{
		lans[n] = (list->zero == 1 ? '0' : ' ');
		n++;
	}
	lans[n] = '\0';
	return (lans);
}

static char		*largif(t_int *list, char *lans, char *ans, int i)
{
	int c;
	int n;

	c = 0;
	while (c < (list->larg - i))
	{
		lans[c] = (list->zero == 1 ? '0' : ' ');
		c++;
	}
	n = 0;
	while (ans[n] != '\0')
	{
		lans[c + n] = ans[n];
		n++;
	}
	lans[c + n] = '\0';
	return (lans);
}

char			*ft_intlarg(t_int *list, int i, char *ans)
{
	char	*lans;
	int		c;
	int		n;

	c = 0;
	c = (list->neg == 1 ? list->larg + 2 : list->larg + 1);
	if (!(lans = (char*)malloc(sizeof(char) * c)))
		return (0);
	if (list->dash == 0)
		lans = largif(list, lans, ans, i);
	else if (list->dash == 1)
		lans = largelse(list, lans, ans);
	if (list->neg == 1 && list->zero == 1)
	{
		n = 1;
		while (lans[n] != '-')
			n++;
		lans[n] = '0';
		lans[0] = '-';
	}
	return (lans);
}
