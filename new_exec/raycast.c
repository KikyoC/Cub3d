#include "../cub3d.h"

int	generate_color(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	increment_ray(t_ray *ray, t_point ***map)
{
	while (can_access(ray->ray_x, ray->ray_y, map) && map[(int)ray->ray_y][(int)ray->ray_x]->c != '1')
	{
		ray->ray_x += ray->cos;
		ray->ray_y += ray->sin;
	}
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

t_ray	create_ray(t_game *game, double start_x)
{
    t_ray	ray;
        
    ray.ray_x = game->player->x;
    ray.ray_y = game->player->y;
    ray.cos = cos(start_x);
    ray.sin = sin(start_x);
    ray.map_x = (int)(ray.ray_x / 64);
    ray.map_y = (int)(ray.ray_y / 64);
    ray.delta_dist_x = (ray.cos == 0) ? 1e30 : fabs(1 / ray.cos);
    ray.delta_dist_y = (ray.sin == 0) ? 1e30 : fabs(1 / ray.sin);
    ray.step_x = (ray.cos < 0) ? -1 : 1;
    ray.step_y = (ray.sin < 0) ? -1 : 1;
    if (ray.cos < 0)
        ray.side_dist_x = (ray.ray_x / 64 - ray.map_x) * ray.delta_dist_x;
    else
        ray.side_dist_x = (ray.map_x + 1.0 - ray.ray_x / 64) * ray.delta_dist_x;

    if (ray.sin < 0)
        ray.side_dist_y = (ray.ray_y / 64 - ray.map_y) * ray.delta_dist_y;
    else
        ray.side_dist_y = (ray.map_y + 1.0 - ray.ray_y / 64) * ray.delta_dist_y;
    return (ray);
}

t_ray	perform_dda(t_game *game, t_ray ray)
{
    int	hit;

	hit = 0;
    while (hit == 0)
    {
        if (ray.side_dist_x < ray.side_dist_y)
        {
            ray.side_dist_x += ray.delta_dist_x;
            ray.map_x += ray.step_x;
            ray.side = 0;
        }
        else
        {
            ray.side_dist_y += ray.delta_dist_y;
            ray.map_y += ray.step_y;
            ray.side = 1;
        }
        if (!can_access(ray.map_x, ray.map_y, game->map) || game->map[(int)ray.map_y][(int)ray.map_x]->c == '1')
            hit = 1;
    }
	return (ray);
}

void draw(t_game *game, t_ray ray, int count)
{
    double	distance;
    double	height;
    int		start_y;
	int		z;
    int		end;

	z = 0;
	distance = get_distance(game, ray);
	height = (64 / distance) * ((double)game->width / 2);
	start_y = (game->height - height) / 2;
	end = start_y + height;
	while (z < game->height)
	{
		if (z < start_y)
			mlx_put_pixel(game->win_tex, count, z, generate_color(0, 0, 255));
		else if (z >= start_y && z < end)
			mlx_put_pixel(game->win_tex, count, z, generate_color(255, 0, 0));
		else
			mlx_put_pixel(game->win_tex, count, z, generate_color(0, 255, 0));
		z++;
    }
}    

void	ft_raycast(t_game *game)
{
	t_ray	ray;
	int		count;
	double	start_x;
	double	fraction;
	static int	print;

	count = 0;
	fraction = M_PI / 3 / game->width;
	start_x = game->player->direction - M_PI / 6;
	while (count < game->width)
	{
		ray = create_ray(game, start_x);
		ray = perform_dda(game, ray);
		draw(game, ray, count);
		start_x += fraction;
		count ++;
	}
	print = 1;
}
