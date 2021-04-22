VPATH=./srcs_push_swap:./srcs_checker:./srcs_common:
PUSH = push_swap
CHECKER = checker
INC_DIR = ./includes
OBJ_DIR = ./obj
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR)

SRCS_PUSH = push_swap.c find_pos.c long_algo.c return_greater_to_a.c sort_3.c sort_min.c
SRCS_CHECKER = checker.c get_next_line_utils.c get_next_line.c utils_checker.c
SRCS_COMMON = check_arg.c operation_reverse_rotate.c operation_rotate.c operation_swap.c \
			  utils_stack.c utils.c operation_push.c

OBJECTS_PUSH := $(SRCS_PUSH:%.c=$(OBJ_DIR)/%.o)
OBJECTS_CHECKER := $(SRCS_CHECKER:%.c=$(OBJ_DIR)/%.o)
OBJECTS_COMMON := $(SRCS_COMMON:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: srcs_push_swap/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $? -o $@

$(OBJ_DIR)/%.o: srcs_common/%.c
	@gcc $(CFLAGS) -c $? -o $@

$(OBJ_DIR)/%.o: srcs_checker/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $? -o $@

all: $(PUSH) $(CHECKER)

$(PUSH): $(OBJECTS_PUSH) $(OBJECTS_COMMON)
	@gcc $(CFLAGS) $(OBJECTS_PUSH) $(OBJECTS_COMMON) -o $(PUSH)
$(CHECKER): $(OBJECTS_CHECKER) $(OBJECTS_COMMON)
	@gcc $(CFLAGS) $(OBJECTS_CHECKER) $(OBJECTS_COMMON) -o $(CHECKER)

.PHONY: clean fclean re normi
normi:
	norminette ./srcs_push_swap
	norminette ./srcs_checker
	norminette ./srcs_common
clean:
	@rm -r $(OBJ_DIR)
fclean: clean
	@rm $(PUSH) $(CHECKER)
re: fclean all
