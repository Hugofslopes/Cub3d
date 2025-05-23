FLAGS = -Wall -Wextra -Werror -ggdb
CC = cc
INCLUDES = -I includes
SRC_DIR = src
OBJ_DIR = obj
SRC = main.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME = Cub3d
DEPS = $(OBJS:.o=.d)
MLX_DIR = mlx
MLX_ARC = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR = libft
LIBFT_ARC = $(LIBFT_DIR)/libft.a

all: $(LIBFT_ARC) $(MLX_ARC) $(NAME)

$(LIBFT_ARC):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_ARC):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_ARC) $(MLX_ARC)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -r -f $(MLX_DIR)

re: fclean all