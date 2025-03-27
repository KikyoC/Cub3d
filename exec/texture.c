#include "cub3d.h"

int	get_tex_color(t_game *game, t_img *img, int z)
{
	int	color;


	color = 0x00000000;
	if (game->map[(int)game->y][(int)game->x] == '1')
		color = mlx_pixel_get(img, (int)(img->width * (g->x + g->y)) \
			% img->width, z);
	return (color);
}

t_img	*get_texture(t_game *game)
{
	t_img	*img;
	float	ray_cos;
	float	ray_sin;

	ray_cos = game->ray.cos;
	if (ray_cos < 0)
		ray_cos = -ray_cos;
	ray_sin = game->ray.sin;
	if (ray_sin < 0)
		ray_sin = -ray_sin;
	if (game->map[(int)(game->y - ray_sin)][(int)game->x] != '1')
		img = game->images->no;
	else if (game->map[(int)(game->y + ray_sin)][(int)game->x] != '1')
		img = game->images->so;
	else if (game->map[(int)game->y][(int)(game->x + ray_cos)] != '1')
		img = game->images->ea;
	else if (game->map[(int)game->y][(int)(game->x - ray_cos)] != '1')
		img = game->images->we;
	return (img);
}


void	draw_texture(t_game *game, t_img *img, int ray_count, int wall_height)
{
	float	dy;
	float	dist;
	float	cy[2];
	int		z;
	int		color;

	dy = ((float)wall_height * 2) / (float)img->height;
	dist = ((float)game->height / 2) - (float)wall_height;
	cy[1] = dist;
	z = -1;
	while (++z < img->height)
	{
		color = get_tex_color(game, img, z);
		color = get_dist_color(color, dist, 0);
		cy[0] = cy[1];
		while (cy[0] < cy[1] + dy)
		{
			if (cy[0] >= 0 && cy[0] < (float)game->height)
				mlx_pixel_put(&game->win_tex, ray_count, cy[0], color);
			cy[0]++;
		}
		cy[1] += dy;
	}
}
