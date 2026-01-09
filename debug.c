#include "cub3d.h"

void	print_type_id(t_texturepack	all_textures)
{
	printf("NO : %s\n", all_textures.NO->path);
	printf("SO : %s\n", all_textures.SO->path);
	printf("WE : %s\n", all_textures.WE->path);
	printf("EA : %s\n", all_textures.EA->path);
	printf("F : %d, %d, %d\n", all_textures.F_RGB[0], all_textures.F_RGB[1], all_textures.F_RGB[2]);
	printf("C : %d, %d, %d\n", all_textures.C_RGB[0], all_textures.C_RGB[1], all_textures.C_RGB[2]);
}

void	print_map(t_map	map)
{
	printf("file : %s\n", map.file);
	printf("cursor : %d\n", map.cursor);
	printf("nbr cols : %d\n", map.cols);
	printf("nbr rows : %d\n", map.rows);
	printf("map : \n");
	int i = 0;
	while(map.grid[i])
	{
		printf("|%s|\n", map.grid[i]);
		i++;
	}
	printf("\nstart_x : %d, start_y : %d, start_dir : %c\n", map.start_p.x,  map.start_p.y,  map.start_p.type);
}

void	print_all(t_gamestruc	*game)
{
	print_type_id(game->texture);
	printf("\n---------------------------------------\n---------------------------------------\n");
	print_map(game->map);
}
