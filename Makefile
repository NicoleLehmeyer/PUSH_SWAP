.PHONY: all clean fclean re

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -Iinclude

LIBFT_ARCHIVE = include/LIBFT/libft.a

SOURCES = src/assist_correct_input.c \
	src/cost_analysis.c \
	src/ft_printf_checks.c \
	src/initstack.c \
	src/is_correct_input.c \
	src/main.c \
	src/move_seqs.c \
	src/process_args.c \
	src/push.c \
	src/rev_rotate.c \
	src/rotate.c \
	src/sort_small.c \
	src/sort_big.c \
	src/stack.c \
	src/swap.c \
	src/target_position.c \
	src/utils.c \

OBJECTS = $(SOURCES:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_ARCHIVE)
	gcc $(FLAGS) $(LIBFT_ARCHIVE) $(OBJECTS) -o $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	cc $(FLAGS) -Imlx -c $< -o $@

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C LIBFT

clean:
	rm -rf obj
	$(MAKE) fclean -s -C include/LIBFT

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -s -C include/LIBFT

re: fclean all