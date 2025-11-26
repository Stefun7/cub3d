/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:40:30 by stephen           #+#    #+#             */
/*   Updated: 2025/11/26 15:19:57 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int set_type_id(t_texturepack	*t, char *line)
{
	char *trim;

	if(t->C && t->F && t->NO->path && t->SO->path && t->WE->path && t->EA->path)
		return(ALL_SET);
	trim = line;
	while(*trim == ' ' || *trim == '\t')
		trim++;
	if (*trim == '\n' || *trim == '\0')
		return (0);
	if(ft_strncmp(trim, "NO", 2) == 0)
		t->NO->path = get_path_texture(trim + 2);
	else if(ft_strncmp(trim, "SO", 2) == 0)
		t->SO->path = get_path_texture(trim + 2);
	else if(ft_strncmp(trim, "WE", 2) == 0)
		t->WE->path = get_path_texture(trim + 2);
	else if(ft_strncmp(trim, "EA", 2) == 0)
		t->EA->path = get_path_texture(trim + 2);
	// else if(*trim == 'F')
	// 	t->F = get_color(trim + 1);
	// else if(*trim == 'C')
	// 	t->C = get_color(trim + 1);
	else
		return(1);
	return(0);
}

void	init_img(t_texturepack	*all_textures)
{
	all_textures->NO->path = NULL;
	all_textures->NO->ptr = NULL;
	all_textures->NO->x = 0;
	all_textures->NO->y = 0;
	all_textures->SO->path = NULL;
	all_textures->SO->ptr = NULL;
	all_textures->SO->x = 0;
	all_textures->SO->y = 0;
	all_textures->WE->path = NULL;
	all_textures->WE->ptr = NULL;
	all_textures->WE->x = 0;
	all_textures->WE->y = 0;
	all_textures->EA->path = NULL;
	all_textures->EA->ptr = NULL;
	all_textures->EA->x = 0;
	all_textures->EA->y = 0;
	all_textures->C->R = NONE;
	all_textures->C->G = NONE;
	all_textures->C->B = NONE;
	all_textures->F->R = NONE;
	all_textures->F->G = NONE;
	all_textures->F->B = NONE;

}

void	init_texture(t_texturepack	*all_textures)
{
	all_textures->NO = malloc(sizeof(t_img));
	all_textures->SO = malloc(sizeof(t_img));
	all_textures->WE = malloc(sizeof(t_img));
	all_textures->EA = malloc(sizeof(t_img));
	all_textures->F = malloc(sizeof(t_color));
	all_textures->C = malloc(sizeof(t_color));
	//maybe secure
	if (!all_textures->NO || !all_textures->SO || !all_textures->WE ||
	!all_textures->EA || !all_textures->F || !all_textures->C)
		exit_game("Error\nMalloc failed", NULL);
	init_img(all_textures);
}

void set_texture(t_texturepack	*all_textures, char *file)
{
	int		fd;
	char	*line;
	int		except;

	init_texture(all_textures);
	fd = open_fd(file);
	line = get_next_line(fd);
	while(line)
	{
		except = set_type_id(all_textures, line);
		free(line);
		if(except == ALL_SET)
			break;
		else if(except)
			exit_game("Error\nInvalid type identifier !", NULL);
		line = get_next_line(fd);
	}
	close(fd);
}

void	set_check_map(t_gamestruc	*game, char *av_1)
{
	set_texture(&game->texture, av_1);
	print_texture(game->texture);
	// set_map(&game->map, av_1);
}
