NAME= so_long
CC= gcc
FLAGS= -Wall -Wextra -Werror
INCLUDE= ./include

SRC_DIR=./src
SRC= main.c \
	error/put_error.c \
	validator/map_arg_validator.c validator/map_data_validator.c validator/map_content_validator.c validator/map_accessibility_check.c validator/move_validator.c \
	utils/matrix_util.c utils/map_util.c utils/map_access_validator_util.c utils/game_util.c \
	views/game_render.c views/move.c \
	map.c \
	test.c

OBJ_DIR= ./obj
OBJ= $(SRC:.c=.o)

LIBFT_PRINTF_DIR= ./lib/ft_printf
LIBFT_PRINTF= libftprintf.a

LIBMLX_DIR= ./lib/mlx_linux
LIBMLX= libmlx.a

LIBGNL_DIR= ./lib/get_next_line
LIBGNL= get_next_line.a

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/error $(OBJ_DIR)/validator $(OBJ_DIR)/utils $(OBJ_DIR)/views
	$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

$(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF):
	make -C $(LIBFT_PRINTF_DIR)

$(LIBMLX_DIR)/$(LIBMLX):
	make -C $(LIBMLX_DIR)

$(LIBGNL_DIR)/$(LIBGNL):
	make -C $(LIBGNL_DIR)

$(NAME): $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) $(LIBMLX_DIR)/$(LIBMLX) $(LIBGNL_DIR)/$(LIBGNL) $(addprefix $(OBJ_DIR)/, $(OBJ))
	$(CC) $(FLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ)) $(LIBFT_PRINTF_DIR)/$(LIBFT_PRINTF) $(LIBMLX_DIR)/$(LIBMLX) $(LIBGNL_DIR)/$(LIBGNL) -L./lib/mlx_linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_PRINTF_DIR)
	make clean -C $(LIBMLX_DIR)
	make clean -C $(LIBGNL_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PRINTF_DIR)
	make fclean -C $(LIBGNL_DIR)

re: fclean all

.PHONY: all clean fclean re
