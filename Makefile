NAME = push_swap
PUSH_SWAP_LIB = lib_$(NAME).a
LIBFT_PATH = libft/
CC = cc
FLAGS = -Wall -Wextra -Werror
EXTRA_FLAG = -fsanitize=address
HELPERS_PATH = helpers/

HELPERS = $(HELPERS_PATH)int_checker.c

SOURCES = $(HELPERS)

OBJS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	@make --directory=$(LIBFT_PATH)
	@cp $(LIBFT_PATH)/libft.a ./
	@mv libft.a $(PUSH_SWAP_LIB)
	@ar rc $(PUSH_SWAP_LIB) $(OBJS)
	@$(CC) $(FLAGS) -I ./inc main.c -L. -l_$(NAME)

$(OBJS): $(SOURCES)
	@$(CC) -c $(FLAGS) -I ./inc $< -o $@

clean:
	@make clean --directory=$(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean --directory=$(LIBFT_PATH)
	@rm -f $(PUSH_SWAP_LIB)

re: fclean all
