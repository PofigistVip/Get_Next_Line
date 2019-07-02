CFLAGS=-Wall -Wextra -Werror -g3

MAINDIR=../
INCLUDE=$(MAINDIR)
LIBFT=$(MAINDIR)libft

SRC=tester.c \
	$(MAINDIR)get_next_line.c
NAME=tester

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc $(CFLAGS) -o $(NAME) $(SRC) -I $(INCLUDE) -I $(LIBFT)/includes -L $(LIBFT) -lft