CFLAGS=-Wall -Wextra -Werror -g3

MAINDIR=../
INCLUDE=$(MAINDIR)
LIBFT=$(MAINDIR)libft

SRC=tester.c \
	$(MAINDIR)get_next_line.c


all:
	make -C $(LIBFT)
	gcc $(CFLAGS) -o tester $(SRC) -I $(INCLUDE) -I $(LIBFT)/includes -L $(LIBFT) -lft 