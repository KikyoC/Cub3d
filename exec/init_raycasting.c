#include "../cub3d.h"

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

float	distance_to_wall(t_game *game, float ray_angle)
{
	float	dir;

	game->ray.cos = cos(degree_to_radians(ray_angle)) / game->ray.precision;
	game->ray.sin = sin(degree_to_radians(ray_angle)) / game->ray.precision;
	game->x = game->player->x + 0.5;
	game->y = game->player->y + 0.5;
	while (!ft_strchr("1", game->map[(int)game->y][(int)game->x]->c) && \
		sqrt(powf(game->x - game->player->x - 0.5, 2.) + \
		powf(game->y - game->player->y - 0.5, 2.)) < game->ray.lim)
	{
		game->x += game->ray.cos;
		game->y += game->ray.sin;
	}
	dir = sqrt(powf(game->x - game->player->x - 0.5, 2.) + powf(game->y - game->player->y - 0.5, 2.));
	return (dir * cos(degree_to_radians(ray_angle - game->ray.angle)));
}

void	ft_draw(t_game *game, int ray_count, float dist)
{
	int		wall_height;
	//float	d;
	//		j;

	wall_height = (int)(game->height / (1.5 * dist));
	//d = ((float)game->height / 2) - (float)wall_height;
	//j = -1;
	// while (++j < game->height / 2)
	// {
	// 	if (j < d)
	// 		mlx_put_pixel(&game->win_tex, ray_count, j,
	// 			get_dist_color(generate_color(game->images->sky[0], game->images->sky[1], game->images->sky[2]), j));
	// 	else if (j >= (game->height / 2))
	// 		mlx_put_pixel(&game->win_tex, ray_count, j,
	// 			get_dist_color(generate_color(game->images->ground[0], game->images->ground[1], game->images->ground[2]), game->height - j));
	// }
	draw_texture(game, get_texture(game), ray_count, wall_height);
}


void	ft_raycast(t_game *game)
{
	float	dist;
	float	ray_angle;
	int		ray_count;

	ray_angle = game->ray.angle - game->ray.hfov;
	ray_count = -1;
	while (++ray_count < game->width)
	{
		dist = distance_to_wall(game, ray_angle);
		//printf("Distance to wall = %f, width = %i/%i\n", dist, ray_count, game->width);
		ft_draw(game, ray_count, dist);
		ray_angle += game->ray.incre_angle;
	}
}

void	ft_init_ray(t_game *game)
{
	game->ray.angle = game->player->direction;
	game->ray.hfov = 30;
	game->ray.incre_angle = 2 * game->ray.hfov / game->width;
	game->ray.precision = 50;
	game->ray.lim = 11;
}
