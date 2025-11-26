/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: stephen <stephen@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/11/11 19:56:56 by stephen		   #+#	#+#			 */
/*   Updated: 2025/11/25 22:56:53 by stephen		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

int	open_fd(char *file)
{//exit without considering free of anything
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_game("Error\nSomething went wrong when opening the map file...",
			NULL);
	return (fd);
}

void	exit_game(char *error_message, t_gamestruc *game)
{
	printf("%s\n", error_message);
	exit(1);
}

char	*get_path_texture(char *line)
{
	size_t	index;
	size_t	end;
	size_t	after_end;
	char 	*path;

	index = 0;
	while(line[index] == ' ' || line[index] == '\t')
		index++;
	if(index == 0 || ft_strncmp((line + index), "./", 2) != 0)
		return(NULL);
	end = index;
	while(line[end] && (line[end] != ' ' && line[end] != '\t' && line[end] != '\n'))
		end ++;
	after_end = end;
	while(line[after_end] == ' ' && line[after_end] == '\t')
		after_end++;
	if(line[after_end] != '\0' && line[after_end] != '\n')
		return(NULL);
	path = ft_substr(line, index, end - index);
	if(!path)
		return(NULL);
	return(path);
}

void	set_color(t_color 	*color, char *line)
{
	size_t	index;
	size_t	end;
	char 	*col_c;
	int i;

	index = 0;
	i = 0;
	while(i < 3)
	{
		if(!skip_spaces(line, &index))
			return;
		end = index;
		while(ft_isdigit(line[end]))
			end++;
		col_c = ft_substr(line, index, end - index);
		if(i == 0)
			color->R = ft_atoi(col_c);
		else if(i == 1)
			color->G = ft_atoi(col_c);
		else if(i == 2)
			color->B = ft_atoi(col_c);
		skip_spaces(line, &index);
		if(line[index] != ',')
			color->R = NONE;
		index = end;
		i++;
	}
	skip_spaces(line, &index);
	if(line[index] != '\0' && line[index] != '\n')
		color->R = NONE;
}

int	skip_spaces(char *input, size_t *index)
{
	while (input[*index] == ' ' || input[*index] == '\t')
		(*index)++;
	// if (!input[*index])		see if '\n' is ok
	// 	return (0);
	return (1);
}

int	int_in_col(char *line, size_t *index, int *col)
{
	int res;
	int len;

	res = 0;
	len = 0;
	while (ft_isdigit(line[*index]))
	{
		res = res * 10 + (line[*index] - '0');
		(*index)++;
		len++;
	}
	if (len == 0 || res < 0 || res > 255)
		return (0);
	*col = res;
	return (1);
}