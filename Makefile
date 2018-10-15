NAME = wolf3d
SRC = src/main.c \
src/key_hooks.c \
src/move_player.c \
src/get_map_info.c \
src/color_assign.c \
src/draw_image.c \
src/get_direction.c \
src/error_check.c

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 

.SILENT:
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft all
	$(CC) -g -o $(NAME) $(OBJ) $(FLAGS) -I minilibx_macos -lmlx -framework OpenGL -framework AppKit -L libft -lft

 %.o: %.c
	$(CC) -c -o $@ $(FLAGS) $^

clean:
	rm -f $(OBJ)
	make -C libft clean
fclean: clean
	make -C libft fclean
	rm -f $(NAME)
re:	fclean all
