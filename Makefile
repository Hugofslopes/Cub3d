FLAGS = -Wall -Wextra -Werror -ggdb
CC = cc
INCLUDES = -I includes
SRC_DIR = src
OBJ_DIR = obj
SRC = main.c handle_input.c init_mlx.c free_exit.c keys.c test_map.c draw.c floor_ceeling.c \
raycast.c render.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME = cub3D
DEPS = $(OBJS:.o=.d)
MLX_DIR = mlx
MLX_ARC = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR = libft
LIBFT_ARC = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = libft/ft_printf_fd
FT_PRINTF_ARC = $(FT_PRINTF_DIR)/ft_printf_fd.a

all: $(LIBFT_ARC) $(MLX_ARC) $(FT_PRINTF_ARC) $(NAME)

$(FT_PRINTF_ARC):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_ARC):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_ARC):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_ARC) $(MLX_ARC) $(FT_PRINTF_ARC)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -l:ft_printf_fd.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(MLX_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all