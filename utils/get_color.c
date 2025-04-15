#include "../cub3d.h"

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)dst);
}

int get_good_pixel(t_img *img, double x, double z, int wall_height)
{    
    if (wall_height > 0)
        z = z / wall_height * 64;
    else
        z = 0;
    return (get_pixel_color(img, (int)(x * 64) % 64, (int)z % 64));
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

t_img	*get_good_mg(t_ray ray, t_game *game)
{
	if (ray.side == 1 && ray.sin > 0)
		return (game->images->ea);
	if (ray.side == 1 && ray.sin <= 0)
		return (game->images->we);
	if (ray.side == 0 && ray.cos > 0)
		return (game->images->so);
	return (game->images->no);
}

t_img    *get_good_img(t_ray ray, t_game *game)
{
    if (ray.side == 0) // Vertical wall hit
    {
        if (ray.step_x > 0)
            return (game->images->ea);
        else
            return (game->images->we);
    }
    else // Horizontal wall hit
    {
        if (ray.step_y > 0)
            return (game->images->so);
        else
            return (game->images->no);
    }
}
