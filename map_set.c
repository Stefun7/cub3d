/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:40:30 by stephen           #+#    #+#             */
/*   Updated: 2026/01/09 20:54:55 by scesar           ###   ########.fr       */
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

//need to pass game so we can free correctly if error

void	init_map(t_map *map, char *file)
{
	int		fd;
	int		x;
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
		x = ft_strlen(line);
		if (x > map->cols)
			map->cols = x;
		if(*line != '\n')
			map->rows++;
		free(line);
		line = get_next_line(fd);
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

void	set_map(t_map *map, t_gamestruc *game)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = get_to_map(map, &fd);
	if (!valid_line(line, &fd))
		exit_game("Invalid Map !\nLine not valid", game);
	while(line && *line != '\n')
	{
		map->grid[y] = ft_substr(line, 0, ft_strlen(line) - 1);
		set_pos(map, map->grid[y], y);
		if(!map->grid[y])
		{
			close(fd);
			exit_game("Malloc error", NULL);
		}
		free(line);
		line = get_next_line(fd);
		y++;
	}
	if(reach_next_line(line, &fd))
		exit_game("Invalid Map !\nOpen Map are not supported", game);
	close(fd);
	map->grid[y] = NULL;
}

void	set_check_data(t_gamestruc	*game, char *av_1)
{
	game->map.cursor = 0;
	init_texture(&game->texture);
	set_texture(game, &game->texture, av_1);
	check_texture(&game->texture, game);
	init_map(&game->map, av_1);
	set_map(&game->map, game);
	check_map(&game->map, game);
	print_all(game);
}
