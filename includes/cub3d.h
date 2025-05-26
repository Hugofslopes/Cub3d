#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>

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
	int		move_l;
	int		move_r;
	int		move_u;
	int		move_d;
	int		rot_l;
	int		rot_r;
	double	pos_x;
	double	pox_y;
	double	plane_x;
	double	plane_y;
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
} t_game;	

typedef struct s_cub
{
	char		**map;
	t_mlx		mlx_s;
	t_player	t_player;
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

//				PARSE
int		handle_input(int ac, char **av, t_cub *cub);

//				INIT
void	init(t_cub *cub);

//				MLX
int		init_mlx(t_cub *cub);

//				KEYS
int		key_pressed(int key, t_cub *cub);
int		mouse_close(t_cub *cub);

//				UTILS
void	free_exit(t_cub *cub);

//				GAME
void	set_floor_ceiling(t_cub *cub);
void    put_pixel(t_cub *cub, int x, int y, int color);
void	draw_c_f(t_cub *cub, size_t x, size_t y);

#endif