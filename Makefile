.PHONY: all clean fclean re

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

LIBFT_ARCHIVE = LIBFT/libft.a

SOURCES = assist_correct_input.c \
	cost_analysis.c \
	ft_printf_checks.c \
	initstack.c \
	is_correct_input.c \
	main.c \
	move_seqs.c \
	process_args.c \
	push.c \
	rev_rotate.c \
	rotate.c \
	sort_small.c \
	sort_big.c \
	stack.c \
	swap.c \
	target_position.c \
	utils.c \

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT_ARCHIVE)
	gcc $(FLAGS) $(LIBFT_ARCHIVE) $(OBJECTS) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -Imlx -c $< -o $@

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C LIBFT

clean:
	rm -f $(OBJECTS)
	$(MAKE) fclean -s -C LIBFT

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -s -C LIBFT

re: fclean all