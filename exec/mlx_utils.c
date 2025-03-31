#include "../cub3d.h"

//https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

void	mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)dst = color;
}

// void	mlx_area_put(t_img *d, t_pos p, t_pos dim, int color)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	while (++y < dim.y)
// 	{
// 		x = -1;
// 		while (++x < dim.x)
// 			mlx_put_pixel(d, p.x + x, p.y + y, color);
// 	}
// }

int	mlx_pixel_get(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)dst);
}
