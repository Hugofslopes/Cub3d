/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_set_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 09:42:31 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/11 09:42:33 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_no(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->no_set)
		return (ft_printf_fd(2, "%sDuplicate NO texture\n", ERROR), 0);
	flags->no_set = 1;
	return (set_texture_path(&cfg->no_path, value));
}

int	handle_so(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->so_set)
		return (ft_printf_fd(2, "%sDuplicate SO texture\n", ERROR), 0);
	flags->so_set = 1;
	return (set_texture_path(&cfg->so_path, value));
}

int	handle_we(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->we_set)
		return (ft_printf_fd(2, "%sError: Duplicate WE texture\n", ERROR), 0);
	flags->we_set = 1;
	return (set_texture_path(&cfg->we_path, value));
}

int	handle_ea(t_config *cfg, t_config_flags *flags, char *value)
{
	if (flags->ea_set)
		return (ft_printf_fd(2, "%sDuplicate EA texture\n", ERROR), 0);
	flags->ea_set = 1;
	return (set_texture_path(&cfg->ea_path, value));
}

int	set_texture_path(char **dst, char *raw)
{
	char	*trimmed;

	if (!raw)
		return (0);
	trimmed = ft_strtrim(raw, " \t\n");
	if (!trimmed)
		return (0);
	free(*dst);
	*dst = ft_strdup(trimmed);
	free(trimmed);
	if (!*dst)
		return (0);
	return (1);
}
