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
	if(game)
		free_all(game);
	exit(1);
}

int	skip_spaces(char *input, size_t *index)
{
	int i;

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

// char *start_of_map(char *file, int *fd)
// {
// 	char *start;

// 	(*fd) = open_fd(file);
// 	start = get_next_line(fd);
// 	while(start)
// 	{
// 		while (*start == ' ' || *start == '\t')
// 			start++;
// 		if ()
// 	}
// 	if(!start)
// 	{
// 		close(*fd);
// 		return(NULL);
// 	}
// 	return(start);
// }