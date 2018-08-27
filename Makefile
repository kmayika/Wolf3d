NAME = wolf3d
SRC = src/main.c

#LIB	= get_next_line/libft/libft.a

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 

.SILENT:
all: $(NAME)

$(NAME): $(OBJ)
	#@make -C get_next_line/libft/ re
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) -I. $(LIB) -I minilibx_macos /Users/kwezimayikana/minilibx/libmlx.a -framework OpenGL -framework AppKit

 %.o: %.c
	@$(CC) -c -o $@ $(FLAGS) $^

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re:	fclean all
