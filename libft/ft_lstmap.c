/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:25:54 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/11 17:16:20 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*ans;

	if (lst == NULL || f == NULL)
		return (NULL);
	ans = NULL;
	while (lst != NULL)
	{
		aux = ft_lstnew((*f)(lst->content));
		if (!(aux))
		{
			ft_lstclear(&ans, del);
			return (NULL);
		}
		ft_lstadd_back(&ans, aux);
		lst = lst->next;
	}
	return (ans);
}
