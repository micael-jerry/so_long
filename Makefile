NAME= so_long
CC= gcc
FLAGS= -Wall -Wextra -Werror
INCLUDE= ./include

SRC_DIR=./src
SRC= main.c

OBJ_DIR= ./obj
OBJ= $(SRC:.c=.o)

LIBFT_PRINTF_DIR= ./lib/ft_printf
LIBFT_PRINTF= libftprintf.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

$(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF):
	make -C $(LIBFT_PRINTF_DIR)

$(NAME): $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) $(addprefix $(OBJ_DIR)/, $(OBJ))
	$(CC) $(FLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) -o $(NAME)
clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_PRINTF_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re