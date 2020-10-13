/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 16:05:52 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char		*ft_dashoff(t_int *list, char *ans, char *lans)
{
	int		n;

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

static char		*ft_dashon(t_int *list, char *ans, int i, char *lans)
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

static char		*ft_strlarg(t_int *list, int i, char *ans)
{
	char	*lans;

	if (!(lans = (char*)malloc(sizeof(char) * (list->larg + 1))))
		return (0);
	if (list->dash == 0)
		lans = ft_dashon(list, ans, i, lans);
	else if (list->dash == 1)
		lans = ft_dashoff(list, ans, lans);
	return (lans);
}

static char		*ft_strprec(char *is, t_int *list)
{
	char	*ans;
	int		i;

	i = 0;
	if (!(ans = (char*)malloc(sizeof(char) * (list->prec + 1))))
		return (0);
	while (i < list->prec)
	{
		ans[i] = is[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

char			*ft_strflags(char *is, t_int *list)
{
	char	*lans;
	char	*ans;
	int		i;

	i = ft_strlen(is);
	if (list->yepprec == 1 && list->prec < i)
	{
		ans = ft_strprec(is, list);
		i = ft_strlen(ans);
	}
	else
		ans = ft_strdup(is);
	if (list->larg > 0 && list->larg > i)
		lans = ft_strlarg(list, i, ans);
	else
		lans = ft_strdup(ans);
	free(ans);
	return (lans);
}
