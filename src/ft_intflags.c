/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:53:29 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char		*whileprec(char *ans, t_int *list, int i, char *is)
{
	int num;
	int j;

	j = strlen(is);
	num = (list->neg == 1 ? j - 1 : j);
	while (i < ((list->prec + list->neg) - num))
	{
		ans[i] = '0';
		i++;
	}
	i = list->prec + list->neg - 1;
	num--;
	while (num + list->neg > 0)
	{
		ans[i] = is[num + list->neg];
		num--;
		i--;
	}
	if (list->neg == 0)
		ans[i] = is[num + list->neg];
	ans[list->prec + list->neg] = '\0';
	return (ans);
}

static char		*ft_intprec(char *is, t_int *list, int i)
{
	int		num;
	char	*ans;

	num = (list->neg == 1 ? i - 1 : i);
	i = 0;
	if (list->prec > num)
	{
		if (!(ans = (char*)malloc(sizeof(char) * (list->prec + 1 + list->neg))))
			return (0);
		if (list->neg == 1)
		{
			ans[i] = '-';
			i++;
		}
		ans = whileprec(ans, list, i, is);
	}
	else
		ans = ft_strdup(is);
	return (ans);
}

char			*ft_intflags(char *is, t_int *list)
{
	int		i;
	char	*ans;
	char	*lans;

	i = ft_strlen(is);
	if (is[0] == '-')
		list->neg = 1;
	if (list->yepprec == 1)
	{
		list->zero = 0;
		ans = ft_intprec(is, list, i);
		i = ft_strlen(ans);
	}
	else
		ans = ft_strdup(is);
	if (list->larg > 0 && list->larg > i)
		lans = ft_intlarg(list, i, ans);
	else
		lans = ft_strdup(ans);
	free(ans);
	return (lans);
}
