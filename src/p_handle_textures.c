#include "../includes/cub3d.h"

static int	handle_north_south(char *line, t_config *cfg, t_config_flags *f)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (f->parsed_no)
			return (ft_printf_fd(2, "%sDuplicate 'NO' entry\n", ERROR), 0);
		if (f->parse_step != 0)
			return (ft_printf_fd(2, "%s'NO' must come first\n", ERROR), 0);
		f->parsed_no = 1;
		f->parse_step++;
		return (handle_no(cfg, f, line + 3));
	}
	if (!ft_strncmp(line, "SO ", 3))
	{
		if (f->parsed_so)
			return (ft_printf_fd(2, "%sDuplicate 'SO' entry\n", ERROR), 0);
		if (f->parse_step != 1)
			return (ft_printf_fd(2, "%s'SO' must come second\n", ERROR), 0);
		f->parsed_so = 1;
		f->parse_step++;
		return (handle_so(cfg, f, line + 3));
	}
	return (-1);
}

static int	handle_west_east(char *line, t_config *cfg, t_config_flags *f)
{
	if (!ft_strncmp(line, "WE ", 3))
	{
		if (f->parsed_we)
			return (ft_printf_fd(2, "%sDuplicate 'WE' entry\n", ERROR), 0);
		if (f->parse_step != 2)
			return (ft_printf_fd(2, "%s'WE' must come third\n", ERROR), 0);
		f->parsed_we = 1;
		f->parse_step++;
		return (handle_we(cfg, f, line + 3));
	}
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (f->parsed_ea)
			return (ft_printf_fd(2, "%sDuplicate 'EA' entry\n", ERROR), 0);
		if (f->parse_step != 3)
			return (ft_printf_fd(2, "%s'EA' must come fourth\n", ERROR), 0);
		f->parsed_ea = 1;
		f->parse_step++;
		return (handle_ea(cfg, f, line + 3));
	}
	return (-1);
}

static int	handle_floor_ceiling(char *line, t_config *cfg, t_config_flags *f)
{
	if (!ft_strncmp(line, "F ", 2))
	{
		if (f->parsed_f)
			return (ft_printf_fd(2, "%sDuplicate 'F' entry\n", ERROR), 0);
		if (f->parse_step != 4)
			return (ft_printf_fd(2, "%s'F' must come fifth\n", ERROR), 0);
		f->parsed_f = 1;
		f->parse_step++;
		return (handle_floor(cfg, f, line + 2));
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		if (f->parsed_c)
			return (ft_printf_fd(2, "%sDuplicate 'C' entry\n", ERROR), 0);
		if (f->parse_step != 5)
			return (ft_printf_fd(2, "%s'C' must come sixth\n", ERROR), 0);
		f->parsed_c = 1;
		f->parse_step++;
		return (handle_ceiling(cfg, f, line + 2));
	}
	return (-1);
}

int	parse_config_line(char *line, t_config *cfg, t_config_flags *flags)
{
	int	result;

	while (*line == ' ' || *line == '\t')
		line++;
	result = handle_north_south(line, cfg, flags);
	if (result != -1)
		return (result);
	result = handle_west_east(line, cfg, flags);
	if (result != -1)
		return (result);
	result = handle_floor_ceiling(line, cfg, flags);
	if (result != -1)
		return (result);
	return (0);
}
