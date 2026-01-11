/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephen <stephen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:20:26 by stephen           #+#    #+#             */
/*   Updated: 2026/01/11 17:57:28 by stephen          ###   ########.fr       */
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
# define MULTI -2

typedef struct s_item
{
	char	type;
	int		x;
	int		y;
}				t_item;

typedef struct s_img
{
	char	*path;
	void	*ptr;
	int		x;
	int		y;
}				t_img;

typedef struct s_texturepack
{
	t_img		*no;
	t_img		*so;
	t_img		*we;
	t_img		*ea;
	int			f_rgb[3];
	int			c_rgb[3];
	//To convert to MLX color:
	//int color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
}				t_texturepack;

typedef struct s_map
{
	char		*file;
	int			cursor;
	size_t		cols;
	size_t		rows;
	char		**grid;
	t_item		start_p;
}	t_map;

typedef struct s_gamestruc
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_texturepack	texture;
	t_map			map;
}				t_gamestruc;

//data_set
void	verif_args(int ac, char **av);
void	set_check_data(t_gamestruc	*game, char *av_1);

//texture_set
void	init_texture(t_texturepack	*all_textures, t_gamestruc *game);
void	c_init_texture(t_texturepack	*all_textures);
int		set_type_id(t_texturepack	*t, char *line, t_gamestruc *game);
void	check_texture(t_texturepack	*t, t_gamestruc *game);
void	set_texture(t_gamestruc	*game, t_texturepack *all_textures, char *file);

char	*get_path_texture(char *line, t_gamestruc *game);
void	set_color(int RGB[3], char *line);
int		int_in_col(char *line, size_t *index, int *col);

//map_set
void	pre_init_map(t_map *map);
void	init_map(t_map *map, char *file, t_gamestruc *game);
char	*extract_line(char *line);
void	set_map(t_map *map, t_gamestruc *game);

bool	valid_line(char *line, int *fd);
void	set_pos(t_map *map, char *line, int y);
void	check_map(t_map	*map, t_gamestruc	*game);
int		map_open(t_map *map);

bool	cross_sp_x(t_map *map, size_t i, size_t j);
bool	cross_sp_y(t_map *map, size_t i, size_t j);
bool	cross_z_x(t_map *map, size_t i, size_t j);
bool	cross_z_y(t_map *map, size_t i, size_t j);
bool	cross_check(t_map *map, size_t i, size_t j, char c);


//utils
void	verif_args(int ac, char **av);
int		open_fd(char *file, t_gamestruc *game);
size_t	end_read(char *line, int *fd);
int		skip_spaces(char *input, size_t *index);
void	exit_game(char *error_message, t_gamestruc *game);
char	*start_map(char *file, int *fd);
bool	reach_next_line(char *line, int *fd);
char	*get_to_map(t_map *map, int *fd);

//free
void	free_all(t_gamestruc *game);
void	free_textures(t_texturepack *textures);

//debug
void	print_type_id(t_texturepack	all_textures);
void	print_map(t_map	map);
void	print_all(t_gamestruc	*game);

#endif
