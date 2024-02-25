CFLAGS := -Wall -Wextra -Werror
CFILES := src/main.c src/libft_mod.c src/parse.c src/sep_operations.c src/sim_operations.c \
          src/index.c src/sort_b.c src/count_b.c src/do.c src/sort_a.c src/count_a.c
OFILES := $(CFILES:.c=.o)
INCLUDE := include
LIBFT_PATH := libft/
LIBFT := libft.a
NAME := push_swap

all: $(LIBFT) $(NAME)

$(NAME): $(OFILES)
	$(CC) $(OFILES) $(LIBFT_PATH)$(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -I$(INCLUDE) -I$(LIBFT_PATH)$(INCLUDE) $^ -o $@ -g

$(LIBFT):
	@make -C libft

clean:
	@make -C libft clean 
	rm -f $(OFILES)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re $(LIBFT)
