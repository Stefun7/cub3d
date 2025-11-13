/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:56:56 by stephen           #+#    #+#             */
/*   Updated: 2025/11/12 16:40:44 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	open_fd(char *file)
{//exit without considering free of anything
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game("Error\nSomething went wrong when opening the map file...",
			NULL);
	return (fd);
}

void	exit_game(int *error_message, t_gamestruc *game)
{
	ft_printf("%s\n", error_message);
	exit(1);
}

char	*get_path_texture(char *line)
{
	size_t	index;
	size_t	end;
	char 	*path;

	index = 0;
	while(line[index] == ' ' || line[index] == '	')
		index++;
	if(!(ft_strncmp((line + index), "./", 2)))
		return(NULL);
	end = index;
	while(line[end] && (line[end] == ' ' && line[end] == '	'))
		end ++;
	if(line[end + 1] && line[end + 1] != '\n')
		return(NULL);
	path = ft_substr(line, index, end);
	if(!path)
		return(NULL);
	return(path);
}
