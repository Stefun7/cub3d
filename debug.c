#include "cub3d.h"

void	print_texture(t_texturepack	all_textures)
{
	printf("NO : %s\n", all_textures.NO->path);
	printf("SO : %s\n", all_textures.SO->path);
	printf("WE : %s\n", all_textures.WE->path);
	printf("EA : %s\n", all_textures.EA->path);
	printf("F : %d, %d, %d\n", all_textures.F->R, all_textures.F->G, all_textures.F->B);
	printf("C : %d, %d, %d\n", all_textures.C->R, all_textures.C->G, all_textures.C->B);
}