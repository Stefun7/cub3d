/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 23:12:56 by stephen           #+#    #+#             */
/*   Updated: 2026/01/11 17:38:50 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_gamestruc *game)
{
	size_t i;

	i = 0;
	if (game->texture.no->path)
		free(game->texture.no->path);
	if (game->texture.so->path)
		free(game->texture.so->path);
	if (game->texture.we->path)
		free(game->texture.we->path);
	if (game->texture.ea->path)
		free(game->texture.ea->path);
	free(game->texture.no);
	free(game->texture.so);
	free(game->texture.we);
	free(game->texture.ea);
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
