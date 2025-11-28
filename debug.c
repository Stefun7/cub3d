#include "cub3d.h"

void	print_texture(t_texturepack	all_textures)
{
	printf("NO : %s\n", all_textures.NO->path);
	printf("SO : %s\n", all_textures.SO->path);
	printf("WE : %s\n", all_textures.WE->path);
	printf("EA : %s\n", all_textures.EA->path);
	printf("F : %d, %d, %d\n", all_textures.F_RGB[0], all_textures.F_RGB[1], all_textures.F_RGB[2]);
	printf("C : %d, %d, %d\n", all_textures.C_RGB[0], all_textures.C_RGB[1], all_textures.C_RGB[2]);
}