NAME = Cub3d

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH)) -I./libft/ -I/usr/local/include

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = cub3d.h

SRC_NAME = bmp.c detection.c fcts_lists.c init_structs.c main.c \
verification.c draw.c free.c init.c movements.c utils.c distances.c \
colors.c animations.c verification2.c utils2.c

FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

LIBX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
		@gcc -o $(NAME) $(OBJ) minilibx/libmlx.a minilibx/libmlx_Linux.a $(LIB) $(INC)  -lm -lbsd -lX11 -lXext
		@echo "\033[0;31mExecutable Cub3d \033[0m \033[0;32m [OK] \033[0m"

$(LIB):
		@echo "\033[0;33mCompiling...\033[0m"
		@make -C libft/ fclean
		@make -C ./libft/
		@echo "\033[0;34mCompilation libft \033[0m \033[0;32m [OK] \033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c include/cub3d.h
		@mkdir -p $(OBJ_PATH)
		@gcc $(FLAG) $(INC) -o $@ -c $<

clean:
		@make -C libft/ clean
		@rm -rf $(OBJ_PATH)
		@echo "deleted ./obj/"

fclean: clean
		@make -C libft/ fclean
		@rm -rf $(NAME)
		@rm -rf screenshot.bmp
		@echo "deleted ./Cub3d"

re: fclean all

.PHONY: clean fclean re all