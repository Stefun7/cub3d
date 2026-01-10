/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 02:15:30 by stephen           #+#    #+#             */
/*   Updated: 2026/01/10 20:46:34 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_type_id(t_texturepack	*t, char *line)
{
	char	*trim;

	if (t->f_rgb[0] != NONE && t->c_rgb[0] != NONE && t->no->path
		&& t->so->path && t->we->path && t->ea->path)
		return (ALL_SET);
	trim = line;
	while (*trim == ' ' || *trim == '\t')
		trim++;
	if (*trim == '\n' || *trim == '\0')
		return (0);
	if (ft_strncmp(trim, "NO", 2) == 0)
		t->no->path = get_path_texture(trim + 2);
	else if (ft_strncmp(trim, "SO", 2) == 0)
		t->so->path = get_path_texture(trim + 2);
	else if (ft_strncmp(trim, "WE", 2) == 0)
		t->we->path = get_path_texture(trim + 2);
	else if (ft_strncmp(trim, "EA", 2) == 0)
		t->ea->path = get_path_texture(trim + 2);
	else if (*trim == 'F')
		set_color(t->f_rgb, trim + 1);
	else if (*trim == 'C')
		set_color(t->c_rgb, trim + 1);
	else
		return (1);
	return (0);
}

void	c_init_texture(t_texturepack	*all_textures)
{
	all_textures->no->path = NULL;
	all_textures->no->ptr = NULL;
	all_textures->no->x = 0;
	all_textures->no->y = 0;
	all_textures->so->path = NULL;
	all_textures->so->ptr = NULL;
	all_textures->so->x = 0;
	all_textures->so->y = 0;
	all_textures->we->path = NULL;
	all_textures->we->ptr = NULL;
	all_textures->we->x = 0;
	all_textures->we->y = 0;
	all_textures->ea->path = NULL;
	all_textures->ea->ptr = NULL;
	all_textures->ea->x = 0;
	all_textures->ea->y = 0;
	all_textures->f_rgb[0] = NONE;
	all_textures->c_rgb[0] = NONE;
	all_textures->f_rgb[1] = NONE;
	all_textures->c_rgb[1] = NONE;
	all_textures->f_rgb[2] = NONE;
	all_textures->c_rgb[2] = NONE;
}

void	init_texture(t_texturepack	*all_textures, t_gamestruc *game)
{
	all_textures->no = malloc(sizeof(t_img));
	all_textures->so = malloc(sizeof(t_img));
	all_textures->we = malloc(sizeof(t_img));
	all_textures->ea = malloc(sizeof(t_img));
	if (!all_textures->no || !all_textures->so || !all_textures->we
		|| !all_textures->ea)
		exit_game("Malloc failed", game);
	c_init_texture(all_textures);
}

void	set_texture(t_gamestruc	*game, t_texturepack	*all_textures,
	char *file)
{
	int		fd;
	char	*line;
	int		except;

	init_texture(all_textures, game);
	fd = open_fd(file, game);
	line = get_next_line(fd);
	while (line)
	{
		except = set_type_id(all_textures, line);
		free(line);
		if (except == ALL_SET)
		{
			line = get_next_line(fd);
			break ;
		}
		else if (except)
			exit_game("Invalid type identifier !", NULL);
		game->map.cursor++;
		line = get_next_line(fd);
	}
	end_read(line, &fd);
}

void	check_texture(t_texturepack	*t, t_gamestruc *game)
{
	if (!t->no->path || !t->so->path || !t->ea->path || !t->we->path
		|| t->c_rgb[0] == -1 || t->c_rgb[1] == -1 || t->c_rgb[2] == -1
		|| t->f_rgb[0] == -1 || t->f_rgb[1] == -1 || t->f_rgb[2] == -1)
		exit_game("Error\nInvalid type identifier !", game);
}
