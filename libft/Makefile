# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: larlyne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 13:38:08 by larlyne           #+#    #+#              #
#    Updated: 2019/04/21 11:09:52 by larlyne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_bzero.c \
	 ft_memcpy.c \
	 ft_memchr.c \
	 ft_memalloc.c \
	 ft_strnew.c \
	 ft_realloc.c

OBJS=$(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -I includes/ -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

makeitclear: all clean
