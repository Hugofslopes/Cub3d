# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 19:38:46 by hfilipe-          #+#    #+#              #
#    Updated: 2025/06/18 19:47:03 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -ggdb -O3
CC = cc
INCLUDES = -I includes
SRC_DIR = src
OBJ_DIR = obj
SRC = main.c handle_input.c init_mlx.c free_exit.c keys.c floor_ceeling.c \
raycast.c render.c player_rotates.c player_moves.c init.c build_image.c \
check_walls.c raycast_utils.c  parser_handler.c check_map.c\
p_check_f_c_color.c p_handle_textures.c \
p_validate_open_file.c p_set_texture_path.c p_config_line.c p_normalize_map.c \
p_append_line.c p_dup_check_map_cells.c p_flood_fill.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
NAME = cub3D
DEPS = $(OBJS:.o=.d)
MLX_DIR = mlx
MLX_ARC = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_DIR = libft
LIBFT_ARC = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = libft/ft_printf_fd
FT_PRINTF_ARC = $(FT_PRINTF_DIR)/ft_printf_fd.a

SRC_BONUS = main.c handle_input.c init_mlx.c free_exit_bonus.c keys_bonus.c floor_ceeling.c \
raycast.c render.c player_rotates.c player_moves_bonus.c init_bonus.c build_image_bonus.c \
check_walls.c raycast_utils.c draw_mini.c draw_extra_keys.c \
init_keys.c draw_extra_b_rot.c parser_handler.c check_map.c \
p_validate_open_file.c p_set_texture_path.c p_config_line.c p_normalize_map.c \
p_check_f_c_color.c p_handle_textures.c draw_mini2.c \
p_append_line.c p_dup_check_map_cells.c p_flood_fill.c
SRCS_BONUS = $(addprefix $(SRC_DIR)/, $(SRC_BONUS))
OBJ_BONUS_DIR = obj_bonus
OBJS_BONUS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_BONUS_DIR)/%.o, $(SRCS_BONUS))
DEPS_BONUS = $(OBJS_BONUS:.o=.d)
NAME_BONUS = cub3D_bonus

all: $(LIBFT_ARC) $(MLX_ARC) $(FT_PRINTF_ARC) $(NAME)

$(FT_PRINTF_ARC):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_ARC):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_ARC):
	if [ ! -d "$(MLX_DIR)" ]; then git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); fi
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT_ARC) $(MLX_ARC) $(FT_PRINTF_ARC)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT_ARC) $(FT_PRINTF_ARC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEPS)

bonus: $(LIBFT_ARC) $(MLX_ARC) $(FT_PRINTF_ARC) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) $(MLX_FLAGS) $(LIBFT_ARC) $(FT_PRINTF_ARC)

$(OBJ_BONUS_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_BONUS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -MMD -c $< -o $@

-include $(DEPS_BONUS)

clean:
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	if [ -d "$(MLX_DIR)" ]; then rm -rf mlx/obj; fi

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean ; fi
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

delete: 
	rm -rf mlx