/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 13:42:44 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/03 13:35:04 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char charac;
	char *chs;

	charac = (char)c;
	chs = (char*)s;
	while (*chs != charac && *chs != '\0')
		chs++;
	if (*chs == charac)
		return (chs);
	return (0);
}
