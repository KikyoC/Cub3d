/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:05:16 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/16 10:06:02 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_pixel_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)dst);
}

int	get_good_pixel(t_img *img, double x, double z, int wall_height)
{
	if (wall_height > 0)
		z = z / wall_height * 64;
	else
		z = 0;
	return (get_pixel_color(img, (int)(x * 64) % 64, (int)z % 64));
}

t_img	*get_good_img(t_ray ray, t_game *game)
{
	if (ray.side == 0)
	{
		if (ray.step_x > 0)
			return (game->images->ea);
		else
			return (game->images->we);
	}
	else
	{
		if (ray.step_y > 0)
			return (game->images->so);
		else
			return (game->images->no);
	}
}
