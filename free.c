/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 23:12:56 by stephen           #+#    #+#             */
/*   Updated: 2025/12/02 01:46:52 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_gamestruc *game)
{
	if(game->texture.NO->path)
		free(game->texture.NO->path);
	if(game->texture.SO->path)
		free(game->texture.SO->path);
	if(game->texture.WE->path)
		free(game->texture.WE->path);
	if(game->texture.EA->path)
		free(game->texture.EA->path);
	free(game->texture.NO);
	free(game->texture.SO);
	free(game->texture.WE);
	free(game->texture.EA);
}