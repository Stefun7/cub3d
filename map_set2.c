/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:28:57 by scesar            #+#    #+#             */
/*   Updated: 2026/01/12 12:26:22 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_line(char *line, int *fd, int to_f)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != ' '
			&& line[x] != 'N' && line[x] != 'S'
			&& line[x] != 'E' && line[x] != 'W')
		{
			if (to_f)
				free(line);
			if (fd)
				close(*fd);
			return (false);
		}
		x++;
	}
	return (true);
}

void	set_pos(t_map *map, char *line, int y)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] != '0' && line[x] != '1' && line[x] != ' ')
		{
			if (map->start_p.type != NONE)
			{
				map->start_p.type = MULTI;
				return ;
			}
			map->start_p.type = line[x];
			map->start_p.x = x;
			map->start_p.y = y;
		}
		x++;
	}
	return ;
}

void	check_map(t_map	*map, t_gamestruc	*game)
{
	size_t	i;
	int		error;

	i = 0;
	if (!map->grid[i])
		exit_game(EMPTY_MAP, game);
	while (map->grid[i])
	{
		if (!valid_line(map->grid[i], NULL, 0))
			exit_game(INVALID_LINE, game);
		i++;
	}
	if (map->cols < 3 || map->rows < 3)
		exit_game(MIN_DIM, game);
	if (map->start_p.type == NONE)
		exit_game(NO_START, game);
	if (map->start_p.type == MULTI)
		exit_game(MULTI_START, game);
	error = map_open(map);
	if (error)
		exit_game(NO_SURR_W, game);
}

int	map_open(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == '0' || map->grid[i][j] == map->start_p.type)
			{
				if (!cross_check(map, i, j, '0'))
					return (1);
			}
			else if (map->grid[i][j] == ' ')
			{
				if (!cross_check(map, i, j, ' '))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
