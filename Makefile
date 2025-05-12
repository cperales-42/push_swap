NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
OPERATIONS_PATH = operations/
CFILES = $(OPERATIONS_PATH)ft_push.c \
         $(OPERATIONS_PATH)ft_swap.c \
         $(OPERATIONS_PATH)ft_rotate.c \
         $(OPERATIONS_PATH)ft_reverse_rotate.c \
         ft_handle_errors.c \
         ft_link_a_to_b.c \
         ft_link_b_to_a.c \
         ft_push_swap_utils.c \
         ft_stack_init.c \
         ft_turk.c \
         ft_push_swap.c
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

subsystems:
	@make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_LIB) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all subsystems clean fclean re