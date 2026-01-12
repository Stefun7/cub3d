/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:59:53 by scesar            #+#    #+#             */
/*   Updated: 2026/01/12 12:24:04 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_init_map(t_map *map)
{
	map->grid = NULL;
	map->start_p.type = NONE;
	map->start_p.x = 0;
	map->start_p.y = 0;
	map->rows = 0;
	map->cols = 0;
}

void	init_map(t_map *map, char *file, t_gamestruc *game)
{
	size_t	x;
	int		fd;
	char	*line;

	map->file = file;
	pre_init_map(map);
	line = get_to_map(map, &fd);
	while (line != NULL)
	{
		x = ft_strlen(line);
		if (x > map->cols)
			map->cols = x;
		if (*line != '\n')
			map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->cols == 0)
		exit_game(EMPTY_MAP, game);
	map->grid = ft_calloc((map->rows + 1), sizeof(char *));
	if (!map->grid)
		exit_game(MALLOC_ERR, game);
}

char	*extract_line(char *line, t_map *map)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_strlen(line);
	res = malloc(map->cols + 1);
	if (!res)
		return (NULL);
	i = 0;
	if (len > 0 && line[len - 1] == '\n')
		len--;
	while (i < len)
	{
		res[i] = line[i];
		i++;
	}
	while (i < map->cols)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	set_map(t_map *map, t_gamestruc *game)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	line = get_to_map(map, &fd);
	if (!valid_line(line, &fd, 1))
		exit_game(INVALID_LINE, game);
	while (line && *line != '\n')
	{
		map->grid[y] = extract_line(line, map);
		if (!map->grid[y])
		{
			close(fd);
			exit_game(MALLOC_ERR, game);
		}
		set_pos(map, map->grid[y], y);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	if (reach_next_line(line, &fd))
		exit_game(OPEN_MAP, game);
	close(fd);
	map->grid[y] = NULL;
}
