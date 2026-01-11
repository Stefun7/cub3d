/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/1 $1 18:24:28 by stephen           #+#    #+#             */
/*   Updated: 2026/01/10 20:01:54 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_gamestruc	game;

	verif_args(ac, av);
	set_check_data(&game, av[1]);
	free_all(&game);
	return (0);
}
