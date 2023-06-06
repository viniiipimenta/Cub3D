NAME	= cub3D

SRCS	= cub3d.c errors.c \
		src/validation.c src/init.c src/img_load.c src/matrix.c src/color.c src/map_analyze.c \
		src/texture_utils.c src/texture_utils_2.c src/utils_map.c src/utils.c src/validation.c \
		src/utils_2.c src/normalize_map.c\

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

LIBFT	= ./libs/libft/libft.a 

GNL		= ./libs/gnl/get_next_line.a 

ifeq ($(shell uname), Linux)
	MLX_FLAGS	= $(CFLAGS) -L ./libs/mlx_linux -lmlx_Linux -L/usr/lib \
				  -Imlx_linux -lXext -lX11 -lm -lz
	MLX_DIR		= ./libs/mlx_linux
else
	MLX_FLAGS	= $(CFLAGS) -L ./libs/mlx -lmlx -framework OpenGL -framework \
				  AppKit
	MLX_DIR		= ./libs/mlx
endif

%.o: %.c
			cc -c $< $(CFLAGS) -I ./include -o $@

$(NAME):	$(OBJS)
			make -C ./libs/libft
			make -C ./libs/gnl
			make -C $(MLX_DIR)
			cc $^ $(MLX_FLAGS) $(LIBFT) $(GNL) -o $@

all:		$(NAME)

clean:
			rm -rf $(OBJS)
			make clean -C ./libs/libft
			make clean -C ./libs/gnl
			make clean -C $(MLX_DIR)

fclean:		clean
			rm -rf $(NAME)
			rm -rf $(NAME).dSYM
			make fclean -C ./libs/libft
			make fclean -C ./libs/gnl

re:			fclean all

.PHONY:		all clean fclean re