NAME = push_swap
BNS_NAME = checker

SRC =	pushSwap.c \
		stack_opers.c stack_opers1.c stack_opers2.c\
		helpers.c \
		split.c \
		check.c \
		five_sort.c \
		additional.c additional2.c

BNS =	bonus/pushSwapBns.c \
		bonus/stack_opers.c bonus/stack_opers1.c bonus/stack_opers2.c\
		bonus/helpers.c \
		bonus/split.c \
		bonus/check.c \
		bonus/additional2.c \
		bonus/get_next_line.c bonus/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
BNS_OBJ = $(BNS:.c=.o)

FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(BNS_NAME): $(BNS_OBJ)
	$(CC) $(BNS_OBJ) -o $(BNS_NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

bonus: $(BNS_NAME)

clean:
	@$(RM) $(OBJ) $(BNS_OBJ)

fclean: clean
	@$(RM) $(NAME) $(BNS_NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY : $(OBJ) $(BNS_OBJ)