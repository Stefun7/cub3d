/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:40:30 by stephen           #+#    #+#             */
/*   Updated: 2026/01/11 17:18:26 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_args(int ac, char **av)
{
	int	len_av_1;

	if (ac < 2)
		exit_game("You need your map file !", NULL);
	if (ac > 2)
		exit_game("You only need one parameter ! (your map file)", NULL);
	len_av_1 = ft_strlen(av[1]);
	if (len_av_1 < 4 || (ft_strncmp(av[1] + (len_av_1 - 4), ".cub", 4)))
		exit_game("Wrong map format, map must end with '.cub' !", NULL);
}

void	set_check_data(t_gamestruc	*game, char *av_1)
{
	game->map.cursor = 0;
	init_texture(&game->texture, game);
	set_texture(game, &game->texture, av_1);
	check_texture(&game->texture, game);
	init_map(&game->map, av_1, game);
	set_map(&game->map, game);
	check_map(&game->map, game);
	print_all(game);
}
