NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

OPERATIONS_PATH = operations/

COMMON_FILES = $(OPERATIONS_PATH)ft_push.c \
               $(OPERATIONS_PATH)ft_swap.c \
               $(OPERATIONS_PATH)ft_rotate.c \
               $(OPERATIONS_PATH)ft_reverse_rotate.c \
               ft_handle_errors.c \
               ft_link_a_to_b.c \
               ft_link_b_to_a.c \
               ft_push_swap_utils.c \
               ft_stack_init.c \
               ft_turk.c

PUSH_SWAP_FILES = ft_push_swap.c
CHECKER_FILES = checker.c

LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

COMMON_OBJS = $(COMMON_FILES:.c=.o)
PUSH_SWAP_OBJS = $(PUSH_SWAP_FILES:.c=.o)
CHECKER_OBJS = $(CHECKER_FILES:.c=.o)

all: subsystems $(NAME)

subsystems:
	@make -C $(LIBFT_PATH) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

$(NAME): $(COMMON_OBJS) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(LIBFT_LIB) -o $(NAME)

bonus: $(BNAME)

$(BNAME): $(COMMON_OBJS) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(CHECKER_OBJS) $(LIBFT_LIB) -o $(BNAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(COMMON_OBJS) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all subsystems clean fclean re bonus
