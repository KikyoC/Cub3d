#include "../cub3d.h"

int	is_wall(t_point ***map, double p_x, double p_y)
{
	int	x;
	int	y;

	x = p_x / 64;
	y = p_y / 64;
	if (!can_access(x, y, map))
		return (1);
	if (map[y][x]->c == '1')
		return (1);
	return (0);
}

double	get_distance(t_game *game, t_ray ray)
{
	double	res;
	double	angle;
	double	diff;

	if (ray.side == 0)
		res = (ray.map_x - ray.ray_x / 64 + (1.0 - ray.step_x) / 2) / ray.cos;
	else
		res = (ray.map_y - ray.ray_y / 64 + (1.0 - ray.step_y) / 2) / ray.sin;
	angle = atan2(ray.sin, ray.cos);
	diff = angle - game->player->direction;
	while (diff > M_PI)
		diff -= 2 * M_PI;
	while (diff < -M_PI)
		diff += 2 * M_PI;
	return (res * 64 * cos(diff));
}
