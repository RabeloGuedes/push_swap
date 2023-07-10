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
TEST_PATH = test/
HELPERS_PATH = helpers/
MOVEMENTS_PATH = movements/
INC_FLAG = -I ./inc

HELPERS =	$(SRC_PATH)$(HELPERS_PATH)int_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)args_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)create_nodes.c\
			$(SRC_PATH)$(HELPERS_PATH)free_nodes.c\
			$(SRC_PATH)$(HELPERS_PATH)order_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)size_checker.c


MOVEMENTS = $(SRC_PATH)$(MOVEMENTS_PATH)swap.c\
			$(SRC_PATH)$(MOVEMENTS_PATH)push.c\
			$(SRC_PATH)$(MOVEMENTS_PATH)rotate.c


OBJS = $(HELPERS:.c=.o) $(MOVEMENTS:.c=.o)


# Test Variables

STR_ARGS = "2 0 1"
DUPLICANTES_ARGS = 2 0 1 2
ARG_A = "2 0 1"
ARG_B = "3 8 4"
DOUBLE_STR = $(ARG_A) $(ARG_B)
NOT_INT_ARGS = 2 1 one 3
TYPO_ARGS = 0 4 -2 3-
NEGATIVES_ARGS = -2 -7 -3 -1 -5
POSITVES_ARGS = 5 7 1 8 3
GOOD_MIX_ARGS = $(POSITVES_ARGS) $(NEGATIVES_ARGS)

# Test Variables

all: $(NAME)

$(NAME): $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

$(notdir $(OBJS)): $(HELPERS) | $(MOVEMENTS)
	@make --directory=$(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT) ./
	@mv $(LIBFT) $(PUSH_SWAP_LIB)
	@$(CC) -c $(FLAGS) $(INC_FLAG) $(HELPERS) $(MOVEMENTS)

clean:
	@make clean --directory=$(LIBFT_PATH)
	@rm -f $(notdir $(OBJS)) tester

fclean: clean
	@make fclean --directory=$(LIBFT_PATH)
	@rm -rf $(PUSH_SWAP_LIB) $(NAME) $(NAME).dSYM

debug: fclean $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

test: $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAG) $(TEST_PATH)tester.c -o tester $(PUSH_SWAP_LIB_PATH)
	@echo "input: \"$(STR_ARGS)\", expected: Error"
	@sleep 2
	@./tester $(STR_ARGS)
	@sleep 1
	@echo "input: $(DUPLICANTES_ARGS), expected: Error"
	@sleep 2
	@./tester $(DUPLICANTES_ARGS)
	@sleep 1
	@echo "input: \"$(ARG_A)\" \"$(ARG_B)\", expected: Error"
	@sleep 2
	@./tester $(DOUBLE_STR)
	@sleep 1
	@echo "input: $(NOT_INT_ARGS), expected: Error"
	@sleep 2
	@./tester $(NOT_INT_ARGS)
	@sleep 1
	@echo "input: $(TYPO_ARGS), expected: Error"
	@sleep 2
	@./tester $(TYPO_ARGS)
	@sleep 1
	@echo "input: $(NEGATIVES_ARGS), expected: OK"
	@sleep 2
	@./tester $(NEGATIVES_ARGS)
	@sleep 1
	@echo "input: $(POSITVES_ARGS), expected: OK"
	@sleep 2
	@./tester $(POSITVES_ARGS)
	@sleep 1
	@echo "input: $(GOOD_MIX_ARGS), expected: OK"
	@sleep 2
	@./tester $(GOOD_MIX_ARGS)

re: fclean all
