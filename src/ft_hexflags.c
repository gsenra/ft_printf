/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 17:44:30 by gabi42            #+#    #+#             */
/*   Updated: 2020/06/08 16:53:25 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static unsigned char	*dashon(t_int *list, unsigned char *lans,
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

static unsigned char	*dashoff(t_int *list, unsigned char *lans,
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

static unsigned char	*ft_hexlarg(t_int *list, int i, unsigned char *ans)
{
	unsigned char	*lans;

	if (!(lans = (unsigned char*)malloc(sizeof(char) * (list->larg + 1))))
		return (0);
	if (list->dash == 0)
		lans = dashoff(list, lans, ans, i);
	else if (list->dash == 1)
		lans = dashon(list, lans, ans);
	return (lans);
}

static unsigned char	*ft_hexprec(unsigned char *is, t_int *list, int i)
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

unsigned char			*ft_hexflags(unsigned char *is, t_int *list)
{
	int				i;
	unsigned char	*ans;
	unsigned char	*lans;

	i = ft_strlen_uns(is);
	if (list->yepprec == 1)
	{
		list->zero = 0;
		ans = ft_hexprec(is, list, i);
		i = ft_strlen_uns(ans);
	}
	else
		ans = ft_strdup_uns(is);
	if (list->larg > 0 && list->larg > i)
		lans = ft_hexlarg(list, i, ans);
	else
		lans = ft_strdup_uns(ans);
	free(ans);
	return (lans);
}
