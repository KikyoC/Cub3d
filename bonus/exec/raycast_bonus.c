/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:29 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 16:22:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_ray	create_ray(t_game *game, double start_x)
{
	t_ray	ray;

	ray.ray_x = game->player->x;
	ray.ray_y = game->player->y;
	ray.cos = cos(start_x);
	ray.sin = sin(start_x);
	ray.map_x = (int)(ray.ray_x / 64);
	ray.map_y = (int)(ray.ray_y / 64);
	cos_sin_handler(&ray);
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
		if (!can_access(ray.map_x, ray.map_y, game->map)
			|| game->map[(int)ray.map_y][(int)ray.map_x]->c == '1')
			hit = 1;
	}
	ray.distance = get_distance(game, ray);
	return (ray);
}

void	draw(t_game *game, t_ray ray, int count)
{
	double	distance;
	double	height;
	int		start_y;
	int		z;
	int		end;

	z = 0;
	distance = get_distance(game, ray);
	height = (64 / distance) * ((double)game->width / 1.1);
	start_y = (game->height - height) / 2;
	end = start_y + height;
	while (z < game->height)
	{
		if (z < start_y)
			mlx_put_pixel(game->win_tex, count, z, *game->images->sky);
		else if (z >= start_y && z < end)
			mlx_put_pixel(game->win_tex, count, z,
				get_good_pixel(get_good_img(ray, game),
					ray.p_wall,
					(z - start_y),
					height));
		else
			mlx_put_pixel(game->win_tex, count, z, *game->images->ground);
		z++;
	}
}

void	ft_raycast(t_game *game)
{
	t_ray		ray;
	int			count;
	double		start_x;
	double		fraction;

	memset(&ray, 0, sizeof(t_ray));
	count = 0;
	fraction = M_PI / 3 / game->width;
	start_x = game->player->direction - M_PI / 6;
	while (count < game->width)
	{
		ray = create_ray(game, start_x);
		ray = perform_dda(game, ray);
		set_touch(game, &ray);
		draw(game, ray, count);
		start_x += fraction;
		count ++;
	}
	init_minimap(game);
}
