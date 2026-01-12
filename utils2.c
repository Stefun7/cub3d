/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 21:03:02 by scesar            #+#    #+#             */
/*   Updated: 2026/01/12 11:42:58 by scesar           ###   ########.fr       */
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

long	my_atoi(const char *str)
{
	size_t	i;
	int		neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+' )
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && res >= 0)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	res *= neg;
	if (res < INT_MIN || res > INT_MAX || i == 0)
		res = LONG_MIN;
	return (res);
}
