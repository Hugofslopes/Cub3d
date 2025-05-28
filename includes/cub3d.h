#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>

typedef enum e_textures{
	N,
	S,
	w,
	E
}	t_textures;

typedef enum {
    NORTH,
    SOUTH,
    EAST,
    WEST
} WallDirection;

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
}	t_player;

typedef struct s_f_c
{
	int			r;
	int 		g;
	int			b;
}	t_f_c;

typedef struct s_game
{
	int		gamestarted;
	int		floor;
	int		ceiling;
	int		mapx;
	int		mapy;
	int		map_with;
	int		map_height;
	double	ray_values[5000];
	float	hitPositions[1920];
	WallDirection wall_directions[1920];
} t_game;	

typedef struct s_cub
{
	char		**map;
	t_mlx		mlx_s;
	t_player	player;
	t_img_		img;
	t_img_		texture[4];
	char		**textures;
	t_f_c		floor;
	t_f_c		ceiling;
	t_game		game;
}	t_cub;

# define MAX_COLOR 0xFF
# define WWIDTH 1920
# define WHEIGHT 1080
# define ERROR "Error\n"
# define NOPERMISION "the map does not have permission"
# define PI 3.14159
# define CELLSIZE 1
# define MOVE_SPEED 0.5
# define ROTATION_SPEED 0.5
#define NUM_RAYS WWIDTH
#define FOV_ANGLE 110.0 

//				PARSE
int		handle_input(int ac, char **av, t_cub *cub);

//				INIT
void	init(t_cub *cub);
void	init_textures(t_cub *cub, size_t i);

//				MLX
void		init_mlx(t_cub *cub);

//				KEYS
int		key_pressed(int key, t_cub *cub);
int		mouse_close(t_cub *cub);

//				UTILS
void	free_exit(t_cub *cub);

//				GAME
void	set_floor_ceiling(t_cub *cub);
void    put_pixel(t_cub *cub, int x, int y, int color);
void	draw_c_f(t_cub *cub, size_t x, size_t y);

//				RAYCAST/ RENDER
void	raycast_all(t_cub *cub, size_t i, int angle_start, int angle_end, int angle_step);
void	ray(t_cub *cub);
void	renderFrame(t_cub *cub);
int		is_wall(t_cub *cub, int mapX, int mapY);
int		build_next_frame(t_cub *cub);

//				PLAYER
void	move_forward(t_cub *cub);
void	move_back(t_cub *cub);
void	move_left(t_cub *cub);
void	move_right(t_cub *cub);
void	rotate_right(t_cub *cub);
void	rotate_left(t_cub *cub);

//			UTILS
double  deg_to_rad(double degrees);
#endif