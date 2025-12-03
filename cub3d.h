/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:20:26 by stephen           #+#    #+#             */
/*   Updated: 2025/12/02 01:48:27 by stephen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdbool.h>
# include "Libft/inc/libft.h"
# include "Libft/inc/get_next_line.h"
# define ALL_SET 11
# define NONE -1

// typedef struct s_color
// {
// 	int	R;
// 	int	G;
// 	int	B;
// }				t_color;

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
	int			F_RGB[3];
	int			C_RGB[3];
	//To convert to MLX color:
	//int color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];

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

//map_set
void	set_check_map(t_gamestruc	*game, char *av_1);


//utils
int	open_fd(char *file);
int	skip_spaces(char *input, size_t *index);
void	set_color(int	RGB[3], char *line);
int	int_in_col(char *line, size_t *index, int *col);

char	*get_path_texture(char *line);

void	exit_game(char *error_message, t_gamestruc *game);


//free
void	free_all(t_gamestruc *game);

//debug
void	print_texture(t_texturepack	all_textures);