/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:40:30 by stephen           #+#    #+#             */
/*   Updated: 2025/11/12 16:45:35 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int set_type_id(t_texturepack	*t, char *line)
{
	if(t->ceiling != NULL && t->floor != NULL && t->NO != NULL && t->SO != NULL && t->WE != NULL && t->EA != NULL)
		return(ALL_SET);
	else if(ft_strncmp(line, "NO", 2))
		t->NO->path = get_path_texture(line);
	else if(ft_strncmp(line, "SO", 2))
		t->SO->path = get_path_texture(line);
	else if(ft_strncmp(line, "WE", 2))
		t->WE->path = get_path_texture(line);
	else if(ft_strncmp(line, "EA", 2))
		t->EA->path = get_path_texture(line);
	else if(*line == "F")
		t->floor->path = get_path_texture(line);
	else if(*line == "C")
		t->ceiling->path = get_path_texture(line);
	else
		return(1);
	return(0);
}

void set_texture(t_texturepack	*all_textures, char *file)
{
	int		fd;
	char 	*line;
	bool 	except;

	all_textures->ceiling = NULL;
	all_textures->floor = NULL;
	all_textures->NO = NULL;
	all_textures->SO = NULL;
	all_textures->WE = NULL;
	all_textures->EA = NULL;
	fd = open_fd(file);
	line = get_next_line(fd);
	while(line)
	{
		except = set_type_id(all_textures, line);
		if(except)
		{
			free(line);
			if(except == ALL_SET)
				break;
			if (except && except!= ALL_SET)
				exit_game("Error\nWrong type identifier !", NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	set_check_map(t_gamestruc	*game, char *av_1)
{
	set_texture(&game->texture, av_1);
	// set_map(&game->map, av_1);
}