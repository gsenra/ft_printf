/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 16:21:46 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:01:21 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static unsigned char	*dashof(t_int *list, unsigned char *lans,
unsigned char *ans)
{
	int n;

	n = 0;
	while (ans[n] != '\0')
	{
		lans[n] = ans[n];
		n++;
	}
	while (n < list->larg)
	{
		lans[n] = (list->zero == 1 ? '0' : ' ');
		n++;
	}
	lans[n] = '\0';
	return (lans);
}

static unsigned char	*dashon(t_int *list, unsigned char *lans,
unsigned char *ans, int i)
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

static unsigned char	*ft_unslarg(t_int *list, int i, unsigned char *ans)
{
	unsigned char	*lans;
	int				n;

	if (!(lans = (unsigned char*)malloc(sizeof(char) * (list->larg + 1))))
		return (0);
	if (list->dash == 0)
		lans = dashon(list, lans, ans, i);
	else if (list->dash == 1)
		lans = dashof(list, lans, ans);
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

static unsigned char	*ft_unsprec(unsigned char *is, t_int *list, int i)
{
	unsigned char	*ans;
	int				n;

	if (!(ans = (unsigned char*)malloc(sizeof(char) * (list->prec + 1))))
		return (0);
	n = 0;
	while (n < (list->prec - i))
	{
		ans[n] = '0';
		n++;
	}
	i = 0;
	while (is[i] != '\0')
	{
		ans[n + i] = is[i];
		i++;
	}
	ans[i + n] = '\0';
	return (ans);
}

unsigned char			*ft_unsflags(unsigned char *is, t_int *list)
{
	int				i;
	unsigned char	*ans;
	unsigned char	*lans;

	i = ft_strlen_uns(is);
	if (list->yepprec == 1)
		list->zero = 0;
	if (list->yepprec == 1 && list->prec > i)
	{
		ans = ft_unsprec(is, list, i);
		i = ft_strlen_uns(ans);
	}
	else
		ans = ft_strdup_uns(is);
	if (list->larg > 0 && list->larg > i)
		lans = ft_unslarg(list, i, ans);
	else
		lans = ft_strdup_uns(ans);
	free(ans);
	return (lans);
}
