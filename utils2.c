/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:03:02 by scesar            #+#    #+#             */
/*   Updated: 2026/01/12 00:32:49 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	end_read(char *line, int *fd)
{
	size_t	line_read;

	line_read = 0;
	while (line)
	{
		free(line);
		line = get_next_line(*fd);
		line_read++;
	}
	close(*fd);
	return (line_read);
}

bool	reach_next_line(char *line, int *fd)
{
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(*fd);
	}
	if (line)
	{
		free(line);
		close(*fd);
		return (true);
	}
	else
		return (false);
}

char	*get_to_map(t_map *map, int *fd)
{
	char	*line;
	int		i;

	i = 0;
	(*fd) = open_fd(map->file, NULL);
	line = get_next_line(*fd);
	while (i < map->cursor)
	{
		free(line);
		line = get_next_line(*fd);
		i++;
	}
	while (line && (*line == '\n' || *line == '\0'))
	{
		free(line);
		line = get_next_line(*fd);
	}
	return (line);
}
