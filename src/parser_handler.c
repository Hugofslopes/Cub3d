#include "../includes/cub3d.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

// to update printf to ft_printd_fd
int     check_cub_extension(const char *file)
{
        size_t  len;

	len = ft_strlen(file);
	if (len <= 4)
		return (0);
	if (ft_strncmp(file + len - 4, ".cub", 4))
		return (0);
	return (1);
}

int	open_scene_file(const char *filename, int *fd)
{
	if (!check_cub_extension(filename))
		return (printf("Error\nScene file must have .cub extension\n"), 1);
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (printf("Error\n%s: %s\n", filename, strerror(errno)), 1);
	return (0);
}
