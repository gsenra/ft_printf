/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:20:51 by gsenra-a          #+#    #+#             */
/*   Updated: 2020/06/09 16:17:30 by gabi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>

typedef struct	s_int
{
	int		i;
	int		size;
	va_list	args;
	int		zero;
	int		larg;
	int		prec;
	int		dash;
	int		yepprec;
	int		neg;
	int		null;
	int		yepconv;
}				t_int;

int				ft_printf(const char *str, ...);

int				ft_tamanho(unsigned int num);

char			*ft_itoa(int n);

t_int			*ft_convert(const char *str, t_int *counts);

t_int			*ft_ispercent(const char *str, t_int *counts);

void			ft_ischar(char c, t_int *counts);

void			ft_isint(char *is, t_int *counts);

void			ft_isstr(char *is, t_int *counts);

t_int			*ft_other_convert(const char *str, t_int*conts);

void			ft_isunint(unsigned char *is, t_int*counts);

unsigned char	*ft_itoa_best(unsigned int n);

unsigned char	*ft_itoa_ultra(uintptr_t n, unsigned int base);

void			ft_isptr(unsigned char *ans, t_int *counts);

void			ft_ishex(unsigned char *is, t_int *counts, const char *str);

void			ft_isprec(const char *str, t_int *list);

void			ft_isflags(const char *str, t_int *list);

int				ft_torf(const char *str, t_int *list);

char			*ft_intflags(char *is, t_int *list);

void			ft_restarter(t_int *list);

char			*ft_intlarg(t_int *list, int i, char *ans);

void			ft_printpercent(t_int *list);

int				ft_torfplus(const char *str, t_int *list);

int				ft_othertorf(const char *str, int i);

void			ft_charflags(char c, t_int *list);

char			*ft_strflags(char *is, t_int *list);

unsigned char	*ft_unsflags(unsigned char *is, t_int *list);

unsigned char	*ft_hexflags(unsigned char *is, t_int *list);

unsigned char	*ft_ptrflags(unsigned char *is, t_int *list);

unsigned char	*ft_ajustprt(unsigned char *temp, t_int *list);

unsigned char	*ft_itoa_hex(unsigned int n, unsigned int base);

#endif
