/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:19:08 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/05/29 17:30:52 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cwrd(char const *s, char c)
{
	size_t	wrd;
	char	*aux;

	wrd = 0;
	aux = (char*)s;
	while (*aux)
	{
		while (*aux == c)
			aux++;
		if (*aux != c && *aux != '\0')
		{
			wrd++;
			while (*aux != c && *aux != '\0')
				aux++;
		}
	}
	return (wrd);
}

static char		**ft_mlt(char const *s, char c, char **ans)
{
	size_t	wrd;
	size_t	lt;
	char	*aux;

	wrd = 0;
	aux = (char*)s;
	while (*aux)
	{
		lt = 0;
		while (*aux == c)
			aux++;
		if (*aux != c && *aux != '\0')
		{
			while (*aux++ != c && *aux != '\0')
				lt++;
			ans[wrd++] = (char*)ft_calloc((lt + 1), (sizeof(char) + 1));
			if (!(ans))
				return (NULL);
		}
	}
	return (ans);
}

static char		**ft_alt(const char *s, char c, char **ans)
{
	size_t	wrd;
	size_t	lt;
	char	*aux;

	aux = (char*)s;
	wrd = 0;
	while (*aux)
	{
		lt = 0;
		while (*aux == c)
			aux++;
		if (*aux != c && *aux != '\0')
		{
			while (*aux != c && *aux != '\0')
			{
				ans[wrd][lt] = *aux;
				aux++;
				lt++;
			}
			wrd++;
		}
	}
	return (ans);
}

static void		*ft_free_strings(char **strings)
{
	if (strings == NULL)
		return (NULL);
	while (*strings != NULL)
		free(*strings++);
	free(strings);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**ans;

	if (!(s))
		return (NULL);
	if (!(ans = (char**)ft_calloc(((ft_cwrd(s, c)) + 1), sizeof(char*))))
		return (ft_free_strings(ans));
	if (!(ans = ft_mlt(s, c, ans)))
		return (ft_free_strings(ans));
	if (!(ans = ft_alt(s, c, ans)))
		return (ft_free_strings(ans));
	return (ans);
}
