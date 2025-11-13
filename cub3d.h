/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:20:26 by stephen           #+#    #+#             */
/*   Updated: 2025/11/12 16:25:21 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdbool.h>
# include "../Libft/inc/libft.h"
# include "../Libft/inc/get_next_line.h"
# define ALL_SET 11

typedef struct s_img
{
	char	*path;
	void	*ptr;
	int		x;
	int		y;
}				t_img;

typedef struct s_texturepack
{
	t_img		*NO;
	t_img		*SO;
	t_img		*WE;
	t_img		*EA;
	t_img		*floor;
	t_img		*ceiling;

}				t_texturepack;

typedef struct s_data_map
{
	char	*file;
	char	character;
	bool	valid_char;
	bool	valid_map;

}				t_data_map;

typedef struct s_gamestruc
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_texturepack	texture;
	t_data_map		map;
}				t_gamestruc;

#endif

//utils
int	open_fd(char *file);

char	*get_path_texture(char *line);

void	exit_game(char *error_message, t_gamestruc *game);