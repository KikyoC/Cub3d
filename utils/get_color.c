#include "../cub3d.h"

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)dst);
}

int	get_good_pixelll(t_img *img, double x, double z, int wall_height, int print)
{
	if (print)
		printf("Double %f\n", x);
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

int get_good_pixel(t_img *img, double x, double z, int wall_height, int print)
{
    if (print)
        printf("Double %f\n", x);
    
    // Don't do this additional normalization - it's already normalized!
    // x = x - (int)x;
    
    // Scale to texture dimensions
    int tex_x = (int)(x * 64) % 64;
    
    // Handle wall height scaling for z coordinate
    if (wall_height > 0)
        z = z / wall_height * 64;
    else
        z = 0;
    
    int tex_y = (int)z % 64;
    
    return (get_pixel_color(img, tex_x, tex_y));
}

static int	mlx_pixel_get(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(int *)dst);
}

int	get_good_pixell(t_game *game, t_img *img, t_ray ray, int z)
{
	int	color;

	color = 0x00000000;
	if (game->map[(int)ray.map_y][(int)ray.map_x]->c == '1')
		color = mlx_pixel_get(img, (int)(img->width * (ray.map_x + ray.map_y)) \
			% img->width, z);
	return (color);
}
