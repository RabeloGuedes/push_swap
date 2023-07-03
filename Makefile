NAME = push_swap
PUSH_SWAP_LIB = lib_$(NAME).a
PUSH_SWAP_LIB_PATH = -L. -l_$(NAME)
LIBFT = libft.a
LIBFT_PATH = ./libft/
CC = cc
FLAGS = -Wall -Wextra -Werror
EXTRA_FLAG = -fsanitize=address
HELPERS_PATH = helpers/
INC_FLAG = -I ./inc

HELPERS = 	$(HELPERS_PATH)int_checker.c

SOURCES = $(HELPERS)

OBJS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(INC_FLAG) $(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

$(notdir $(OBJS)): $(SOURCES)
	@make --directory=$(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT) ./
	@mv $(LIBFT) $(PUSH_SWAP_LIB)
	@$(CC) -c $(FLAGS) $(INC_FLAG) $(SOURCES)

clean:
	@make clean --directory=$(LIBFT_PATH)
	@rm -f $(notdir $(OBJS))

fclean: clean
	@make fclean --directory=$(LIBFT_PATH)
	@rm -f $(PUSH_SWAP_LIB) $(NAME)

re: fclean all
