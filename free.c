/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 23:12:56 by stephen           #+#    #+#             */
/*   Updated: 2026/01/12 11:48:48 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_gamestruc *game)
{
	free_textures(&game->texture);
	free_map(&game->map);
}

void	free_textures(t_texturepack *textures)
{
	if (textures->no)
	{
		if (textures->no->path)
			free(textures->no->path);
		free(textures->no);
	}
	if (textures->so)
	{
		if (textures->so->path)
			free(textures->so->path);
		free(textures->so);
	}
	if (textures->ea)
	{
		if (textures->ea->path)
			free(textures->ea->path);
		free(textures->ea);
	}
	if (textures->we)
	{
		if (textures->we->path)
			free(textures->we->path);
		free(textures->we);
	}
}

void	free_map(t_map *map)
{
	size_t	i;

	i = 0;
	if (map->grid)
	{
		while (map->grid[i])
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}
