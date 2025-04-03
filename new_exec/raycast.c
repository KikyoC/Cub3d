#include "../cub3d.h"

float	to_radians(float degree)
{
	return (degree * M_PI / 180);
}

int	generate_color(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

t_ray distance_to_wall(t_game *game, float ray_angle)
{
	t_ray	ray;
	float	r_cos;
	float	r_sin;

	ray.x_s = game->player->x;
	ray.x_e = game->player->x;
	ray.y_s = game->player->y;
	ray.y_e = game->player->y;
	r_cos = cos(to_radians(ray_angle));
	r_sin = sin(to_radians(ray_angle));
	printf("Cos is %f and sin is %f\n", r_cos, r_sin);
	while (can_access(ray.x_e, ray.y_e, game->map) && game->map[(int)ray.y_e][(int)ray.x_e]->c != '1')
	{
		ray.x_e += r_cos;
		ray.y_e += r_sin;
		printf("Not on the wall\n");
		mlx_put_pixel(game->win_tex, ray.x_e, ray.y_e, generate_color(255, 255, 255));
	}
	return (ray);
}

void	ft_raycast(t_game *game)
{
	//printf("Width %i height %i, Player pos x=%f y=%f\n", game->width, game->height, game->player->x, game->player->y);
	distance_to_wall(game, game->player->direction);
}
