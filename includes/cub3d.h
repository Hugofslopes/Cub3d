#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_player
{
	int	move_l;
	int	move_r;
	int	move_u;
	int	move_d;
	int	rot_l;
	int	rot_r;
}	t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_config_flags
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
} t_config_flags;

typedef struct s_config
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int 	floor_color_set;
	int	ceiling_color_set;
	t_rgb	floor_color;
	t_rgb	ceiling_color;
}	t_config;

typedef struct s_cub
{
	char		**map;
	t_mlx		mlx_s;
	t_player	t_player;
	t_config	config;
	t_config_flags	flags;
	int		map_height;
}	t_cub;

# define MAX_COLOR 0xFFFFFF
# define WWIDTH 1920
# define WHEIGHT 1080
# define ERROF "Error\n"
# define NOPERMISION "the map does not have permission"
# define EXTENSION_ERR "Scene file must have .cub extension\n"
# define READ_FILE_ERR "Failed opening file\n"
# define CONF_ENTR_ERR "Missing or invalid config entries\n"

//				PARSE
int		handle_input(int ac, char **av, t_cub *cub);

//				MLX
int		init_mlx(t_cub *cub);

//				KEYS
int		key_pressed(int key, t_cub *cub);
int		mouse_close(t_cub *cub);

//				UTILS
void	free_exit(t_cub *cub);
void	free_config(t_config *cfg);
void	free_map(char **map);

//				PARSING_P
int	open_scene_file(const char *filename, int *fd);
int	parse_scene_file(int *fd, t_cub *cub);
#endif
