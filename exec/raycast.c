# include "../cub3d.h"
#include <math.h>
#include <stdio.h>

float to_radians(int degrees)
{
	return (degrees * M_PI / 180);
}

float	distance_to_wall(t_game *game, float ray_angle)
{
	float	dir;

	game->ray.cos = cosf(to_radians(ray_angle)) / game->ray.precision;
	game->ray.sin = sinf(to_radians(ray_angle)) / game->ray.precision;
	game->x = game->player->x + 0.5;
	game->y = game->player->y + 0.5;
	while (can_access(game->x, game->y, game->map) && \
		!ft_strchr("1", game->map[(int)game->y][(int)game->x]->c) && \
		sqrtf(powf(game->x - game->player->x - 0.5, 2.) + \
		powf(game->y - game->player->y - 0.5, 2.)) < game->ray.lim)
	{
		game->x += game->ray.cos;
		game->y += game->ray.sin;
	}
	dir = sqrtf(powf(game->x - game->player->x - 0.5, 2.) + powf(game->y - game->player->y - 0.5, 2.));
	return (dir * cos(to_radians(ray_angle - game->ray.angle)));
}

float	ft_distance()
{

}

void	ft_raycast(t_game *game)
{
	int		x;
	double	camera_x;
	double ray_dir_x;
	double ray_dir_y;

	x = 0;
	while (x < game->width)
	{


		x++;
	}
	
}

void	ft_init_ray(t_game *game)
{
	game->ray.angle = game->player->direction;
	game->ray.hfov = 30;
	game->ray.incre_angle = 2 * game->ray.hfov / game->width;
	game->ray.precision = 67;
	game->ray.lim = 11;
}
