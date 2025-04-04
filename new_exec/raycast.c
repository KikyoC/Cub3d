#include "../cub3d.h"
#include <math.h>

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
	while (can_access(ray.x_e, ray.y_e, game->map) && game->map[(int)ray.y_e][(int)ray.x_e]->c != '1')
	{
		ray.x_e += r_cos;
		ray.y_e += r_sin;
		//mlx_put_pixel(game->win_tex, ray.x_e + 100, ray.y_e + 100, generate_color(0, 0, 255));
	}
	return (ray);
}

void ft_draw(t_game *game, t_ray ray, int count)
{
    int 	distance;
	int		wall_height;
	float	d;
    int		z;

	distance = sqrtf(powf(ray.x_e - ray.x_s, 2) + powf(ray.y_e - ray.y_s, 2));
	wall_height = game->height / (1.5 * distance);
	d = ((float)game->height / 2) - wall_height;
	//Draw the height wall
	z = 0;
	while (z < game->height)
	{
		if (z < d)
			mlx_put_pixel(game->win_tex, count, z, generate_color(0, 0, 255));
		else if (z >= d && z < d + wall_height)
			mlx_put_pixel(game->win_tex, count, z, generate_color(255, 0, 0));
		else
			mlx_put_pixel(game->win_tex, count, z, generate_color(0, 0, 0));
		z++;
	}
}

//void	ft_ray_draw(t_game *game, t_ray ray, float angle)
//{
//	int	distance;

//	distance = sqrtf(powf(ray.x_e - ray.x_s, 2) + powf(ray.y_e - ray.y_s, 2));
	
//}

void	ft_raycast(t_game *game)
{
	t_ray	ray;
	float	angle;
	int		count;
	
	count = 0;
	angle = game->player->direction - 30;
	while (count <= game->width)
	{
		ray = distance_to_wall(game, angle);
		ft_draw(game, ray, count);
		angle += 120.0 / game->width;
		count ++;
	}
}
