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

typedef enum e_textures
{
	N,
	S,
	w,
	E
}	t_textures;

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
}	t_player;

typedef struct s_f_c
{
	int	r;
	int	g;
	int	b;
}	t_f_c;

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
	int					map_with;
	int					map_height;
	double				ray_values[1920];
	float				hit_positions[1920];
	t_wall_direction	wall_directions[1920];
}	t_game;	

typedef struct s_cub
{
	char		**map;
	t_mlx		mlx_s;
	t_player	player;
	t_img_		img;
	t_img_		texture[4];
	t_img_		keys[12];
	t_keys		keys_;
	char		**textures;
	t_f_c		floor;
	t_f_c		ceiling;
	t_game		game;
	t_mini		mini;
	t_move		moves;
	t_render	rend;
	t_ray		rayc;
}	t_cub;

# define MAX_COLOR 0xFF
# define WWIDTH 1920
# define WHEIGHT 1080
# define ERROR "Error\n"
# define NOPERMISION "the map does not have permission"
# define IFILE "Invalid file: "
# define CIMAGE "Failed to creat new image: "
# define CHECKFILE "Check if the file exists and is in the right folder!\n"
# define PI 3.14159
# define ROTATION_SPEED 45
# define NUM_RAYS 1920
# define FOV_ANGLE 90.0 
# define FIXED_POINT 256
# define HALF_FIXED 128

//				PARSE
int		handle_input(int ac, char **av, t_cub *cub);

//				INIT
void	init(t_cub *cub);
void	init_textures(t_cub *cub, size_t i);

//				MLX
void	init_mlx(t_cub *cub);

//				KEYS
int		key_pressed(int key, t_cub *cub);
int		mouse_close(t_cub *cub);

//				CLOSE PROGRAM
void	free_exit(t_cub *cub, int value);
void	free_exit_textures(t_cub *cub);
void	free_exit_keys(t_cub *cub);

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
int		is_out_of_map(t_cub *cub, double x, double y);

#endif