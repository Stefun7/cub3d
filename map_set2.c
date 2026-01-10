/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:28:57 by scesar            #+#    #+#             */
/*   Updated: 2026/01/10 19:12:34 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	valid_line(char *line, int *fd)
{
	int x;

	x = 0;
	while(line[x] && line[x] != '\n')
	{
		if(line[x] != '0' && line[x] != '1' && line[x] != ' '
				&& line[x] != 'N' && line[x] != 'S' && line[x] != 'E' && line[x] != 'W')
		{
			free(line);
			if(fd)
				close(*fd);
			return (false);
		}
		x++;
	}
	return(true);
}

void	set_pos(t_map *map, char *line, int y)
{
	int	x;

	x = 0;
	while(line[x])
	{
		if(line[x] != '0' && line[x] != '1' && line[x] != ' ')
		{
			if(map->start_p.type != NONE)
			{
				map->start_p.type = MULTI;
				return;
			}
			map->start_p.type = line[x];
			map->start_p.x = x;
			map->start_p.y = y;
		}
		x++;
	}
	return;
}

void	check_map(t_map	*map, t_gamestruc	*game)
{
	size_t	i;
	int	error;

	i = 0;
	if(!map->grid[i])
		exit_game("Invalid Map !\nYou actually need a map...", game);
	while (map->grid[i])
	{
		if(!valid_line(map->grid[i], NULL))
			exit_game("Invalid Map !\nOnly 1, 0, N, S, W, E and spaces accepted", game);
		i++;
	}
	if(map->cols < 3 || map->rows < 3)
		exit_game("Invalid Map !\nAt least 3x3 map required !", game);
	if(map->start_p.type == NONE)
		exit_game("Invalid Map !\nNeed a starting position !", game);
	if(map->start_p.type == MULTI)
		exit_game("Invalid Map !\nCan't have more than one starting position !", game);
	error = map_open(map);
	//more precise message here with maccro
	if(error)
		exit_game("Invalid Map !\nMap not closed !", game);
}

int map_open(t_map *map)
{
	size_t i;
	size_t j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while(map->grid[i][j])
		{
			if(map->grid[i][j] == '0' || map->grid[i][j] == map->start_p.type)
			{
				if(!cross_check(map, i, j, '0'))
					return(1);
			}
			else if(map->grid[i][j] == ' ')
			{
				if(!cross_check(map, i, j, ' '))
					return(1);
			}
			j++;
		}
		i++;
	}
	return(0);
}

bool cross_sp_x(t_map *map, size_t i, size_t j)
{
	size_t x;

	x = 0;
	while (x < j)
	{
		if (map->grid[i][x] != ' ')
			break;
		x++;
	}
	if(x == j)
		return(true);
	x = j + 1;
	while (x < ft_strlen(map->grid[i]))
	{
		if (map->grid[i][x] != ' ')
			break;
		x++;
	}
	if(x == ft_strlen(map->grid[i]))
		return(true);
	return(false);
}

bool cross_sp_y(t_map *map, size_t i, size_t j)
{
	size_t y;

	y = 0;
	while (y < i)
	{
		if (map->grid[y][j] != ' ')
			break;
		y++;
	}
	if(y == i)
		return(true);
	y = i + 1;
	while (y < map->rows)
	{
		if (map->grid[y][j] != ' ')
			break;
		y++;
	}
	if(y == map->rows)
		return(true);
	return(false);
}

bool cross_z_x(t_map *map, size_t i, size_t j)
{
	size_t x;

	x = 0;
	while (x < j)
	{
		if (map->grid[i][x] == '1')
			break;
		x++;
	}
	if(x == j)
		return(false);
	x = j + 1;
	while (x < ft_strlen(map->grid[i]))
	{
		if (map->grid[i][x] == '1')
			break;
		x++;
	}
	if(x == ft_strlen(map->grid[i]))
		return(false);
	return(true);
}

bool cross_z_y(t_map *map, size_t i, size_t j)
{
	size_t y;

	y = 0;
	while (y < i)
	{
		if (map->grid[y][j] == '1')
			break;
		y++;
	}
	if(y == i)
		return(false);
	y = i + 1;
	while (y < map->rows)
	{
		if (map->grid[y][j] == '1')
			break;
		y++;
	}
	if(y == map->rows)
		return(false);
	return(true);
}

bool cross_check(t_map *map, size_t i, size_t j, char c)
{
	if(c == '0')
	{
		if(!(cross_z_x(map, i, j)) || !(cross_z_y(map, i, j)))
			return(false);
	}
	else if(c == ' ')
	{
		if(!(cross_sp_x(map, i, j)) && !(cross_sp_y(map, i, j)))
			return(false);
	}
	return(true);
}

/*
11111
 111E1
1101101
 10000111111
  1111
111
*/
