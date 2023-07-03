NAME = push_swap
PUSH_SWAP_LIB = lib_$(NAME).a
PUSH_SWAP_LIB_PATH = -L. -l_$(NAME)
CC = cc
FLAGS = -Wall -Wextra -Werror
EXTRA_FLAG = -fsanitize=address
HELPERS_PATH = helpers/
INC_FLAG = -I ./inc

HELPERS = 	$(HELPERS_PATH)int_checker.c $(HELPERS_PATH)ft_format_checker.c $(HELPERS_PATH)ft_itoa.c\
			$(HELPERS_PATH)ft_print_address.c $(HELPERS_PATH)ft_print_hex.c $(HELPERS_PATH)ft_print_int.c\
			$(HELPERS_PATH)ft_print_strchr.c $(HELPERS_PATH)ft_print_uint.c $(HELPERS_PATH)ft_printf.c

SOURCES = $(HELPERS)

OBJS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(notdir $(OBJS))
	@ar rc $(PUSH_SWAP_LIB) $(notdir $(OBJS))
	@$(CC) $(FLAGS) $(INC_FLAG) $(NAME).c -o $(NAME) $(PUSH_SWAP_LIB_PATH)

$(notdir $(OBJS)): $(SOURCES)
	@$(CC) -c $(FLAGS) $(INC_FLAG) $(SOURCES)

clean:
	@rm -f $(notdir $(OBJS))

fclean: clean
	@rm -f $(PUSH_SWAP_LIB) $(NAME)

re: fclean all
