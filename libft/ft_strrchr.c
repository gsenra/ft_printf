/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsenra-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:52:45 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/02/03 15:38:08 by gsenra-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned char *chfs;
	unsigned char *chis;
	unsigned char charac;

	chfs = (unsigned char*)s;
	chis = (unsigned char*)s;
	charac = (unsigned char)c;
	while (*chfs != '\0')
		chfs++;
	if (c == '\0')
		return ((char*)chfs);
	while (*chfs != charac && *chfs != *chis)
	{
		chfs--;
		if (*chfs == charac)
			return ((char*)chfs);
	}
	return (0);
}
