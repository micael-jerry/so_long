NAME= get_next_line.a
CC= gcc
FLAGS= -Wall -Wextra -Werror
INCLUDE= ./

SRC_DIR=./
SRC= get_next_line_utils.c get_next_line.c

OBJ_DIR= ./obj
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJ))
	ar -rc $(NAME) $(addprefix $(OBJ_DIR)/,$(OBJ))

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
