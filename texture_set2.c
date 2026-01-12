/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_set2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scesar <scesar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 05:42:24 by stephen           #+#    #+#             */
/*   Updated: 2026/01/12 11:44:30 by scesar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_path_texture(char *line, t_gamestruc *game, char *p)
{
	size_t	index;
	size_t	end;
	size_t	after_end;
	char	*path;

	if (p)
		exit_game(MULTI_ID, game);
	index = 0;
	while (line[index] == ' ' || line[index] == '\t')
		index++;
	if (index == 0 || ft_strncmp((line + index), "./", 2) != 0)
		return (NULL);
	end = index;
	while (line[end] && (line[end] != ' ' && line[end] != '\t'
			&& line[end] != '\n'))
		end ++;
	after_end = end;
	while (line[after_end] == ' ' && line[after_end] == '\t')
		after_end++;
	if (line[after_end] != '\0' && line[after_end] != '\n')
		return (NULL);
	path = ft_substr(line, index, end - index);
	if (!path)
		exit_game(MALLOC_ERR, game);
	return (path);
}

void	set_color(int rgb[3], char *line)
{
	size_t	index;
	int		i;

	index = 0;
	i = 0;
	if (*line != ' ' && *line != '\t')
		return ;
	while (i < 3)
	{
		skip_spaces(line, &index);
		if (!int_in_col(line, &index, &rgb[i]))
			return ;
		skip_spaces(line, &index);
		if (i < 2)
		{
			if (line[index] != ',')
				return ;
			index++;
		}
		i++;
	}
	skip_spaces(line, &index);
	if (line[index] != '\0' && line[index] != '\n')
		rgb[0] = NONE;
}

// int	int_in_col(char *line, size_t *index, int *col)
// {
// 	size_t	start;
// 	int		res;

// 	start = *index;
// 	if (!ft_isdigit(line[*index]))
// 		return (0);
// 	while (ft_isdigit(line[*index]))
// 		(*index)++;
// 	res = ft_atoi(&line[start]);
// 	if (res < 0 || res > 255)
// 		return (0);
// 	*col = res;
// 	return (1);
// }

int	int_in_col(char *line, size_t *index, int *col)
{
	size_t	start;
	long	res;

	start = *index;
	if (!ft_isdigit(line[*index]))
		return (0);
	while (ft_isdigit(line[*index]))
		(*index)++;
	res = my_atoi(&line[start]);
	if (res < 0 || res > 255)
		return (0);
	*col = (int)res;
	return (1);
}
