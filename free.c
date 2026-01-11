/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 23:12:56 by stephen           #+#    #+#             */
/*   Updated: 2026/01/12 00:32:03 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_gamestruc *game)
{
	size_t i;

	free_textures(&game->texture);
	i = 0;
	if (game->map.grid)
	{
		while (game->map.grid[i])
		{
			if (game->map.grid[i])
				free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
	}
}

void	free_textures(t_texturepack *textures)
{
	if (textures->no)
	{
		if (textures->no->path)
			free(textures->no->path);
	}
	if (textures->so)
	{
		if (textures->so->path)
			free(textures->so->path);
	}
	if (textures->ea)
	{
		if (textures->ea->path)
			free(textures->ea->path);
	}
	if (textures->we)
	{
		if (textures->we->path)
			free(textures->we->path);
	}
}
