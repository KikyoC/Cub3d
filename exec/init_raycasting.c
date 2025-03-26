#include "../cub3d.h"

void	init_ray(t_game *game)
{
	game->ray.angle = 0;
	if (game->player->point->c == 'S')
		game->ray.angle = 90;
	else if (game->player->point->c == 'W')
		game->ray.angle = 180;
	else if (game->player->point->c == 'N')
		game->ray.angle = 270;
	game->ray.hfov = 30;
	game->ray.incre_angle = 2 * game->ray.hfov / game->width;
	game->ray.precision = 50;
	game->ray.lim = 11;
}
