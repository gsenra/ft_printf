# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabi42 <gabi42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/29 16:05:49 by gabi42            #+#    #+#              #
#    Updated: 2020/06/07 17:58:35 by gabi42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

DIR_SRC = src

DIR_OBJS = objs

HEADER = include

SOURCES = ft_aux.c ft_charflags.c ft_hexflags.c ft_intflags.c ft_intlarg.c ft_isflags.c \
ft_ispercent.c ft_isprec.c ft_otheraux.c ft_printbasics.c ft_printf.c ft_printother.c \
ft_printpercent.c ft_ptrflags.c ft_strflags.c ft_torfs.c ft_unsflags.c

SRC = $(addprefix $(DIR_SRC)/,$(SOURCES))

OBJS = $(addprefix $(DIR_OBJS)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(DIR_OBJS)/%.o: $(DIR_SRC)/%.c
	mkdir -p objs
	gcc -Wall -Wextra -Werror -g -I $(HEADER) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

bonus: fclean all

.PHONY: all clean fclean re bonus