/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:07:38 by scesar            #+#    #+#             */
/*   Updated: 2026/01/10 21:09:56 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	cross_sp_x(t_map *map, size_t i, size_t j)
{
	size_t	x;

	x = 0;
	while (x < j)
	{
		if (map->grid[i][x] != ' ')
			break ;
		x++;
	}
	if (x == j)
		return (true);
	x = j + 1;
	while (x < ft_strlen(map->grid[i]))
	{
		if (map->grid[i][x] != ' ')
			break ;
		x++;
	}
	if (x == ft_strlen(map->grid[i]))
		return (true);
	return (false);
}

bool	cross_sp_y(t_map *map, size_t i, size_t j)
{
	size_t	y;

	y = 0;
	while (y < i)
	{
		if (map->grid[y][j] != ' ')
			break ;
		y++;
	}
	if (y == i)
		return (true);
	y = i + 1;
	while (y < map->rows)
	{
		if (map->grid[y][j] != ' ')
			break ;
		y++;
	}
	if (y == map->rows)
		return (true);
	return (false);
}

bool	cross_z_x(t_map *map, size_t i, size_t j)
{
	size_t	x;

	x = 0;
	while (x < j)
	{
		if (map->grid[i][x] == '1')
			break ;
		x++;
	}
	if (x == j)
		return (false);
	x = j + 1;
	while (x < ft_strlen(map->grid[i]))
	{
		if (map->grid[i][x] == '1')
			break ;
		x++;
	}
	if (x == ft_strlen(map->grid[i]))
		return (false);
	return (true);
}

bool	cross_z_y(t_map *map, size_t i, size_t j)
{
	size_t	y;

	y = 0;
	while (y < i)
	{
		if (map->grid[y][j] == '1')
			break ;
		y++;
	}
	if (y == i)
		return (false);
	y = i + 1;
	while (y < map->rows)
	{
		if (map->grid[y][j] == '1')
			break ;
		y++;
	}
	if (y == map->rows)
		return (false);
	return (true);
}

bool	cross_check(t_map *map, size_t i, size_t j, char c)
{
	if (c == '0')
	{
		if (!(cross_z_x(map, i, j)) || !(cross_z_y(map, i, j)))
			return (false);
	}
	else if (c == ' ')
	{
		if (!(cross_sp_x(map, i, j)) && !(cross_sp_y(map, i, j)))
			return (false);
	}
	return (true);
}
