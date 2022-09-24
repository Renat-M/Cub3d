NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -I includes/ -I libft/ -MMD

LIBFT = -L libft/ -lft

HEADERS = includes/cub3d.h

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

MAIN_SRC = 	cast_walls.c		\
			cast_walls2.c		\
			keys.c				\
			key_funcs.c			\
			key_funcs2.c		\
			main.c				\
			mouse.c				\
			textures.c

PARSER = 	bool_handling.c	\
			bool_handling2.c	\
			free_data.c			\
			print_error.c			\
			handling_color.c	\
			handling_data.c		\
			init_data.c			\
			map_error.c			\
			map_parser.c		\
			read_map.c			\
			replace_file.c

GNL = 		get_next_line.c		\
			get_next_line_utils.c

SRC = $(addprefix srcs/, $(MAIN_SRC))\
		$(addprefix srcs/parser/, $(PARSER))\
		$(addprefix srcs/get_next_line/, $(GNL))

OBJ = $(SRC:c=o)
DEP = $(OBJ:o=d)

PATH_LIB = libft/
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(HDRS)
	@make -C mlx 2>/dev/null
	@make -C $(PATH_LIB)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) -I mlx $(OBJ) $(LIB) -I. -o $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make fclean -C $(PATH_LIB)
	@make clean -C mlx
	@rm -f $(OBJ) $(DEP)

fclean:
	@make fclean -C $(PATH_LIB)
	@make clean -C mlx
	@rm -f $(OBJ) $(DEP)
	@rm -f $(NAME)

test: all clean

re: fclean all

.PHONY: all clean fclean re test

include $(wildcard $(DEP))