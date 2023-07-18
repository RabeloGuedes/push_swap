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
TEST_OUTPUT_FILES = test_output_files/
TEST_100 = test_100/
TEST_500 = test_500/
HELPERS_PATH = helpers/
MOVEMENTS_PATH = movements/
INC_FLAG = -I ./inc

HELPERS =	$(SRC_PATH)$(HELPERS_PATH)int_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)args_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)create_nodes.c\
			$(SRC_PATH)$(HELPERS_PATH)free_nodes.c\
			$(SRC_PATH)$(HELPERS_PATH)order_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)size_checker.c\
			$(SRC_PATH)$(HELPERS_PATH)ft_lst_find.c\
			$(SRC_PATH)$(HELPERS_PATH)calcalute_least_rotations.c\
			$(SRC_PATH)$(HELPERS_PATH)handle_rotations_a.c\
			$(SRC_PATH)$(HELPERS_PATH)handle_rotations_b.c\
			$(SRC_PATH)$(HELPERS_PATH)sort.c\
			$(SRC_PATH)$(HELPERS_PATH)rotations_cost.c


MOVEMENTS = $(SRC_PATH)$(MOVEMENTS_PATH)swap.c\
			$(SRC_PATH)$(MOVEMENTS_PATH)push.c\
			$(SRC_PATH)$(MOVEMENTS_PATH)rotate.c

TESTS = $(TEST_PATH)display_nodes.c

OBJS = $(HELPERS:.c=.o) $(MOVEMENTS:.c=.o) $(TESTS:.c=.o)

# Colors
BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
SUPER_RED = \033[91m
SUPER_GREEN = \033[92m
SUPER_YELLOW = \033[93m
SUPER_BLUE = \033[94m
SUPER_MAGENTA = \033[95m
SUPER_CYAN = \033[96m
# Colors

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
TEST_LINES := 0;
# Test Variables

all: $(NAME)

$(NAME): $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

$(notdir $(OBJS)): $(HELPERS) $(MOVEMENTS) $(TESTS)
	@make --directory=$(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT) ./
	@mv $(LIBFT) $(PUSH_SWAP_LIB)
	@$(CC) -c $(FLAGS) $(INC_FLAG) $(HELPERS) $(MOVEMENTS) $(TESTS)

clean:
	@make clean --directory=$(LIBFT_PATH)
	@rm -f $(notdir $(OBJS)) tester

fclean: clean
	@make fclean --directory=$(LIBFT_PATH)
	@rm -rf $(PUSH_SWAP_LIB) $(NAME) $(NAME).dSYM $(TEST_OUTPUT_FILES)

debug: fclean $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

test_input: $(notdir $(OBJS))
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

test_files_lines: fclean $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAG) $(SRC_PATH)$(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)
	@test $(TEST_OUTPUT_FILES) | mkdir $(TEST_OUTPUT_FILES)
	@test $(TEST_OUTPUT_FILES)$(TEST_100) | mkdir $(TEST_OUTPUT_FILES)$(TEST_100)
	@test $(TEST_OUTPUT_FILES)$(TEST_500) | mkdir $(TEST_OUTPUT_FILES)$(TEST_500)
	@echo "$(YELLOW)Testing 100 times with 100 random numbers$(WHITE)"
	@for i in $$(seq 1 100); do ./$(NAME) $$(shuf -i 0-500 -n 100) > $(TEST_OUTPUT_FILES)$(TEST_100)test_100_numbers$$i.txt; done
	@echo "$(SUPER_YELLOW)Testing 100 times with 500 random numbers$(WHITE)"
	@echo "$(SUPER_RED)Be patient it takes some time$(WHITE)"
	@for i in $$(seq 1 100); do ./$(NAME) $$(shuf -i 0-5000 -n 500) > $(TEST_OUTPUT_FILES)$(TEST_500)test_500_numbers$$i.txt; done
	@make test_100
	@make test_500
	
test_100:
	@cd test && sh test_output_100_random_numbers.sh

test_500:
	@cd test && sh test_output_500_random_numbers.sh
re: fclean all
