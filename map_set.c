/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:40:30 by stephen           #+#    #+#             */
/*   Updated: 2026/01/04 03:21:32 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int find_map_start(char *file)
// {
// 	int		fd;
// 	int		line_index;
// 	char	*line;

// 	fd = open_fd(file);
// 	line = get_next_line(fd);
// 	line_index = 1;
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		if (*line == '\n' || *line == '\0')
// 		{
// 			free(line);
// 			line_index++;
// 			continue;
// 		}
// 		else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
// 			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2)
// 			|| *line == 'F' || *line == 'C')
// 		{
// 			free(line);
// 			line_index++;
// 			continue;
// 		}
// 		else
// 			break;
// 	}
// 	close(fd);
// 	return (line_index);
// }

void	check_map(t_map	*map, t_gamestruc	*game)
{

}

void	set_pos(t_map *map, char *line, int fd, int y)
{
	int	x;

	x = 0;
	if(map->start_p.type != NONE)
		return;
	while(line[x])
	{
		if(line[x] != '0' && line[x] != '1' && line[x] != ' ')
		{
			map->start_p.type = line[x];
			map->start_p.x = x;
			map->start_p.y = y;
			return;
		}
		x++;
	}
	return;
}

//need to pass game so we can free correctly if error
void	init_map(t_map *map, char *file)
{
	int		fd;
	int		y;
	char	*line;

	map->start_p.type = NONE;
	map->start_p.x = 0;
	map->start_p.y = 0;
	map->rows = 0;
	map->cols = 0;
	map->file = file;
	line = get_to_map(map, &fd);
	while (line != NULL)
	{
		y = ft_strlen(line);
		map->cols = y;
		if (y > map->cols)
			map->cols = y;
		free(line);
		line = get_next_line(fd);
		map->rows++;
	}
	close(fd);
	if (map->cols == 0)
		exit_game("Error\nEmpty map !", NULL);
	map->grid = (char **)malloc(sizeof(char *) * (map->rows + 1));
	if(!map->grid)
		exit_game("Malloc error", NULL);
}

char *get_to_map(t_map *map, int *fd)
{
	char *line;
	int	i;

	i = 0;
	(*fd) = open_fd(map->file);
	line = get_next_line(*fd);
	i = 0;
	while(i < map->cursor)
	{
		free(line);
		line = get_next_line(*fd);
		i++;
	}
	while(*line == '\n' || *line == '\0')	//check if work with empty map
	{
		free(line);
		line = get_next_line(*fd);
	}
	return(line);
}

void	set_map(t_map *map, char *file)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = get_to_map(map, &fd);
	while(line)
	{
		map->grid[y] = ft_strdup(line);
		if(!map->grid[y])
		{
			close(fd);
			exit_game("Malloc error", NULL);
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	map->grid[y] = NULL;
}

void	set_check_map(t_gamestruc	*game, char *av_1)
{
	game->map.cursor = 0;
	init_texture(&game->texture);
	set_texture(game, &game->texture, av_1);
	check_texture(&game->texture, game);
	// print_type_id(game->texture);
	init_map(&game->map, av_1);
	set_map(&game->map, av_1);
	print_all(game);
	check_map(&game->map, game);
}
