#include "../cub3d.h"

int	get_dist_color(int color, float dist)
{
	(void)dist;
	return (color);
}

int	get_tex_color(t_game *game, t_img *img, int z)
{
	int	color;

	color = 0x00000000;
	if (game->map[(int)game->y][(int)game->x]->c == '1')
		color = mlx_pixel_get(img, (int)(img->width * (game->x + game->y)) \
			% img->width, z);
	return (color);
}

t_img	*get_texture(t_game *game)
{
	t_img	*img;
	float	ray_cos;
	float	ray_sin;

	img = NULL;
	ray_cos = fabs(game->ray.cos);
	ray_sin = fabs(game->ray.sin);
	if (can_access(game->x, game->y - ray_sin, game->map) && \
	game->map[(int)(game->y - ray_sin)][(int)game->x]->c != '1')
		img = game->images->no;
	else if (can_access(game->x, game->y + ray_sin, game->map) && \
		game->map[(int)(game->y + ray_sin)][(int)game->x]->c != '1')
		img = game->images->so;
	else if (can_access(game->x + ray_cos, game->y, game->map) && \
		game->map[(int)game->y][(int)(game->x + ray_cos)]->c != '1')
		img = game->images->ea;
	else if (can_access(game->x - ray_cos, game->y, game->map) && \
		game->map[(int)game->y][(int)(game->x - ray_cos)]->c != '1')
		img = game->images->we;
	return (img);
}

static void	draw_verticality(float *cy, t_game *game, int ray_count, int color)
{
	while (cy[0] < cy[1])
	{
		if (cy[0] >= 0 && cy[0] < (float)game->height)
			mlx_put_pixel(game->win_tex, ray_count, cy[0], color);
		cy[0]++;
		if (cy[0] < -500 || cy[0] > (float)game->height + 300)
			break ;
	}
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
		color = get_dist_color(color, dist);
		cy[0] = cy[1];
		cy[1] += dy;
		draw_verticality(cy, game, ray_count, generate_color(255, 0, 0));
	}
}
