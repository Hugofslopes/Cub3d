/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:08:12 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/06/11 13:34:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>

typedef struct s_mini
{
	int	player_x;
	int	player_y;
	int	rect_x;
	int	rect_y;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	e2;
}	t_mini;

typedef struct s_move
{
	double	dx;
	double	dy;
	double	nx;
	double	ny;
}	t_move;

typedef enum e_wall_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_wall_direction;

typedef struct s_img_
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bytes_p_pixel;
	int		line_len;
	int		endian;
}	t_img_;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_player
{
	char	start_position;
	float	pos_x;
	float	pos_y;
	double	ray_x;
	double	ray_y;
	double	ray_angle;
	double	angle;
	float	speed;
	int		faster;
}	t_player;

typedef struct s_rgb //added PS
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_config_flags //added PS
{
	int	no_set;
	int	so_set;
	int	we_set;
	int	ea_set;
	int	f_set;
	int	c_set;
	int	parse_step;
	int	parsed_no;
	int	parsed_so;
	int	parsed_we;
	int	parsed_ea;
	int	parsed_f;
	int	parsed_c;
}	t_config_flags;

typedef struct s_config //added PS
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		floor_color_set;
	int		ceiling_color_set;
	t_rgb	floor_color;
	t_rgb	ceiling_color;
}	t_config;

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	rl;
	int	rr;
	int	b;
	int	nb;
	int	arms;
}	t_keys;

typedef struct s_rend
{
	double				brightness;
	unsigned int		base_color;
	int					texy;
	int					texx;
	int					line_height;
	int					texture_index;
	int					draw_end;
	int					draw_start;
	double				prj_pln_dt;
	double				dist;
	t_wall_direction	wall_side;
}	t_render;

typedef struct s_ray
{
	double	angle;
	int		mapx;
	int		mapy;
	double	raydirx;
	double	raydiry;
	double	deltadistx;
	double	deltadisty;
	double	wall_hit;
	int		side;
	int		hit;
	int		stepx;
	int		stepy;
	double	wall_dist;
	double	side_dstx;
	double	side_dsty;
}	t_ray;

typedef struct s_game
{
	int					gamestarted;
	int					floor;
	int					ceiling;
	int					mapx;
	int					mapy;
	int					cellsize;
	double				ray_values[1600];
	float				hit_positions[1600];
	t_wall_direction	wall_directions[1600];
}	t_game;	

typedef struct s_pos_info
{
	int		i;
	int		j;
	char	c;
}	t_pos_info;

typedef struct s_cub
{
	char			**map;
	t_mlx			mlx_s;
	t_player		player;
	t_img_			img;
	t_img_			texture[4];
	t_img_			keys[12];
	t_keys			keys_;
	char			**textures;
	t_rgb			floor;
	t_rgb			ceiling;
	t_game			game;
	t_mini			mini;
	t_move			moves;
	t_render		rend;
	t_ray			rayc;
	t_config		config;
	t_config_flags	flags;
	int				map_height;
	int				map_width;
	char			**map_copy;
	int				player_x;
	int				player_y;
}	t_cub;

# define MAX_COLOR 0xFF
# define WWIDTH 1600
# define WHEIGHT 900
# define PI 3.14159
# define ROTATION_SPEED 45
# define NUM_RAYS 1600
# define FOV_ANGLE 90.0 
# define FIXED_POINT 256
# define HALF_FIXED 128
# define ERROR "Error\n"
# define ARGNB "Wrong number of arguments\n"
# define NOPERMISION "the map does not have permission"
# define IFILE "Invalid file: "
# define CIMAGE "Failed to creat new image: "
# define CHECKFILE "Check if the file exists and is in the right folder!\n"
# define EXTENSION_ERR "Scene file must have .cub extension\n"
# define READ_FILE_ERR "Failed opening file\n"
# define CONF_ENTR_ERR "Missing or invalid config entries\n"
# define TEXTURE "texture missing\n"
# define EXTENSION_ERR "Scene file must have .cub extension\n" //added PS
# define READ_FILE_ERR "Failed opening file\n" //added PS
# define CONF_ENTR_ERR "Missing or invalid config entries\n" //added PS
# define ZERO_PLAYER "More than one player position was found\n" //added PS

//				PARSE
int		handle_input(int ac, char **av, t_cub *cub);
int		open_scene_file(const char *filename, int *fd);
int		parse_scene_file(int *fd, t_cub *cub);
int		parse_config_line(char *line, t_config *cfg, t_config_flags *flags);
int		handle_no(t_config *cfg, t_config_flags *flags, char *value);
int		handle_so(t_config *cfg, t_config_flags *flags, char *value);
int		handle_we(t_config *cfg, t_config_flags *flags, char *value);
int		handle_ea(t_config *cfg, t_config_flags *flags, char *value);
int		handle_floor(t_config *cfg, t_config_flags *flags, char *value);
int		handle_ceiling(t_config *cfg, t_config_flags *flags, char *value);
int		parse_rgb(char *raw, t_rgb *color);
int		check_cub_extension(const char *file);
int		open_scene_file(const char *filename, int *fd);
int		is_space_char(char c);
int		is_line_empty(char *line);
int		set_texture_path(char **dst, char *raw);
int		is_config_line(char *line);
int		check_texture(const char *path);
int		validate_config(t_config *cfg);
int		check_map_no_empty_lines(char **map);
int		get_max_width(char **map, int height);
int		fill_normalized_row(char *src, char *dst, int width);
void	free_partial_map(char **map, int until);
int		normalize_map(t_cub *cub);
void	free_2d_partial(char **arr, int until);
char	**ft_realloc_2d(char **old, int new_size);
int		append_map_line(t_cub *cub, char *line);
int		all_config_flags_set(t_config_flags *flags, t_config *config);
int		validate_map_chars_support(t_cub *cub, int *count, t_pos_info *pos);
int		validate_map_chars(t_cub *cub);
void	dup_map(t_cub *cub);
void	init_visited(t_cub *cub, int ***visited);
int		check_unreachable_cells(t_cub *cub, int **visited);
void	cube_flood_fill(t_cub *cub, int **visited, int x, int y);
void	free_visited(int **visited, int height);
int		map_is_close_support(t_cub *cub, int y, int x);
int		map_is_closed(t_cub *cub);
int		parse_map(t_cub *cub);
int		handle_config_line(char *line, t_cub *cub, char **buffer);
int		process_line(char *line, t_cub *cub, int *map_started, char **buffer);
int		handle_map_empty_error(t_cub *cub);
int		handle_parse_map_error(t_cub *cub);
int		parse_scene_file(int *fd, t_cub *cub);
void	check_map_first(t_cub *cub, char *line, char **buffer);

//				INIT
void	init(t_cub *cub);
void	init_textures(t_cub *cub, size_t i);

//				MLX
void	init_mlx(t_cub *cub);

//				KEYS
int		key_pressed(int key, t_cub *cub);
int		mouse_close(t_cub *cub);
int		key_released(int key, t_cub *cub);

//				CLOSE PROGRAM
void	free_exit(t_cub *cub, int value);
void	free_exit_textures(t_cub *cub, size_t i);
void	free_config(t_config *cfg);
void	free_array(char **map);

//				GAME
void	set_floor_ceiling(t_cub *cub);
void	put_pixel(t_cub *cub, int x, int y, int color);
void	draw_c_f(t_cub *cub, size_t x, size_t y);

//				RAYCAST/ RENDER
void	ray(t_cub *cub, int i);
void	render_frame(t_cub *cub, int x, double hit_pos);
int		is_wall(t_cub *cub, int mapX, int mapY);
int		is_wall_move(t_cub *cub, int dir_x, int dir_y);
int		build_next_frame(t_cub *cub);

//				PLAYER
void	move_forward(t_cub *cub, double angle_rad);
void	move_back(t_cub *cub, double angle_rad);
void	move_left(t_cub *cub, double angle_rad);
void	move_right(t_cub *cub, double angle_rad);
void	rotate_right(t_cub *cub);
void	rotate_left(t_cub *cub);

//				UTILS
double	deg_to_rad(double degrees);
double	normalize_angle(double angle);
void	set_wall_side(t_cub *cub, t_wall_direction *wall_side);
#endif
