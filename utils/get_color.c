#include "../cub3d.h"

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)dst);
}

int	get_good_pixel(t_img *img, double x, double z, int wall_height)
{
	x = x - (int)x;
	x *= 64;
	if (wall_height > 0)
		z = z / wall_height * 64;
	else
	{
		z = 0;
		//printf("Here\n");
	}
	//printf("Searching in (%f,%f) with height %i\n", x, z, wall_height);
	//if (x >= 64
	//	|| z >= 64)
	return (get_pixel_color(img, x, z));
}
