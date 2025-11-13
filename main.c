/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:24:28 by stephen           #+#    #+#             */
/*   Updated: 2025/11/12 14:53:51 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verif_args(int ac, char **av)
{
	int	len_av_1;

	if (ac < 2)
		exit_game("Error\nYou need your map file !", NULL);
	if (ac > 2)
		exit_game("Error\nYou only need one parameter ! (your map file)", NULL);
	len_av_1 = ft_strlen(av[1]);
	if (len_av_1 < 4 || (ft_strncmp(av[1] + (len_av_1 - 4), ".cub", 4)))
		exit_game("Error\nWrong map format, map must end with '.cub' !", NULL);
}

int	main(int ac, char **av)
{
	t_gamestruc	game;

	verifarg(ac, av);
	set_check_map(&game, av[1]);

}