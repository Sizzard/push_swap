CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = src/linked_list.c src/parsing.c src/push.c src/reverse_rotate.c src/rotate.c src/sort.c src/swap.c src/rank.c src/error.c src/sort_utils.c src/sort_short.c\
	main.c

NAME = push_swap
OBJETS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJETS) libft/libftprintf.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJETS) libft/libftprintf.a

libft/libftprintf.a:
	make -C libft 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJETS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
	make -C libft re

.PHONY: all clean fclean re 