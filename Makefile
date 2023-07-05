NAME = push_swap
PUSH_SWAP_LIB = lib_$(NAME).a
PUSH_SWAP_LIB_PATH = -L. -l_$(NAME)
LIBFT = libft.a
LIBFT_PATH = ./libft/
CC = cc
FLAGS = -Wall -Wextra -Werror
SANITIZE_FLAG = -fsanitize=address
DEBUG_FLAGS = -g $(SANITIZE_FLAG)
SRC_PATH = src/
HELPERS_PATH = helpers/
INC_FLAG = -I ./inc

HELPERS =	$(HELPERS_PATH)int_checker.c $(HELPERS_PATH)duplicates_checker.c

OBJS = $(HELPERS:.c=.o)


all: $(NAME)

$(NAME): $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

$(notdir $(OBJS)): $(HELPERS)
	@make --directory=$(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT) ./
	@mv $(LIBFT) $(PUSH_SWAP_LIB)
	@$(CC) -c $(FLAGS) $(INC_FLAG) $(HELPERS)

clean:
	@make clean --directory=$(LIBFT_PATH)
	@rm -f $(notdir $(OBJS))

fclean: clean
	@make fclean --directory=$(LIBFT_PATH)
	@rm -rf $(PUSH_SWAP_LIB) $(NAME) $(NAME).dSYM

debug: $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

re: fclean all
