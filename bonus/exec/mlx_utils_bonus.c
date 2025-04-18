/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:34 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/18 19:37:20 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)dst = color;
}

int	*generate_color(int red, int green, int blue)
{
	int	*res;

	res = ft_calloc(1, sizeof(int));
	if (!res)
		return (NULL);
	*res = red << 16 | green << 8 | blue;
	return (res);
}

void	mlx_put_infos(t_game *game)
{
	int	x;

	x = 30;
	if (game->mini_map)
	{
		x = 200;
		mlx_string_put(game->mlx_ptr, game->win_ptr, x, 30, 0, "Mini map [TAB]: enabled");
	}
	else
		mlx_string_put(game->mlx_ptr, game->win_ptr, x, 30, 0, "Mini map [TAB]: disabled");
	if (game->collisions)
		mlx_string_put(game->mlx_ptr, game->win_ptr, x, 50, 0, "Collisions [C]: enabled");
	else
		mlx_string_put(game->mlx_ptr, game->win_ptr, x, 50, 0, "Collisions [C]: disabled");
	if (game->handle_mouse)
		mlx_string_put(game->mlx_ptr, game->win_ptr, x, 70, 0, "Mouse [M]: enabled");
	else
		mlx_string_put(game->mlx_ptr, game->win_ptr, x, 70, 0, "Mouse [M]: disabled");
}
