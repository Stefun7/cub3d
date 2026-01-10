/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:02:24 by scesar            #+#    #+#             */
/*   Updated: 2026/01/10 21:04:13 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_fd(char *file, t_gamestruc *game)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game("Something went wrong when opening the map file...", game);
	return (fd);
}

void	exit_game(char *error_message, t_gamestruc *game)
{
	printf("Error\n");
	printf("%s\n", error_message);
	if (game)
		free_all(game);
	exit(1);
}

int	skip_spaces(char *input, size_t *index)
{
	int	i;

	i = 0;
	while (input[*index] == ' ' || input[*index] == '\t')
	{
		i++;
		(*index)++;
	}
	if (i == 0)
		return (0);
	return (1);
}
