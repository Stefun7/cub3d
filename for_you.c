/*Here are diffrents data you can have acces after the set_check_data function initialized the t_gamestruc strcut*/

// #include "cub3d.h"

// int	main(int ac, char **av)
// {
// 	t_gamestruc	game;

// 	verif_args(ac, av);
// 	set_check_data(&game, av[1]);

// 	//map (tab of str)
// 	char **map = game.map.grid;

// 	//texture path
// 	//ptr already available in struct for setting them with mlx via game.texture.XX->ptr;
// 	char *NO = game.texture.no->path;
// 	char *EA = game.texture.ea->path;
// 	char *WE = game.texture.we->path;
// 	char *SO = game.texture.so->path;

// 	//floor and ceiling colors as int
// 	int floor[3] = game.texture.f_rgb;
// 	int ceiling[3] = game.texture.c_rgb;
// 	int f_color = (game.texture.f_rgb[0] << 16) | (game.texture.f_rgb[1] << 8) | game.texture.f_rgb[2]
// 	int c_color = (game.texture.c_rgb[0] << 16) | (game.texture.c_rgb[1] << 8) | game.texture.c_rgb[2]

// 	//starting position
// 	char direction = game.map.start_p.type;
// 	int x = game.map.start_p.x;
// 	int y = game.map.start_p.y;

// 	free_all(&game);
// 	return (0);
// }
