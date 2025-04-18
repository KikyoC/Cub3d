/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:42:21 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/18 13:51:57 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	pxl(t_game *game, int pos[2], int map_x, int map_y)
{
	if (game->map[map_y][map_x]->c == '1')
		draw_square(game->win_tex, pos, 255 * 256 * 256);
	else
		draw_square(game->win_tex, pos, 0);
}

void	draw_map_line(t_game *game, int map_y, int win_y)
{
	int	win_x;
	int	map_x;
	int	pos[2];

	win_x = -1;
	while (++win_x < 11)
	{
		map_x = (int)game->player->x / 64 - 5 + win_x;
		if (map_x < 0)
			continue ;
		if (!game->map[map_y][map_x])
			break ;
		pos[0] = win_x * SQUARE;
		pos[1] = win_y * SQUARE;
		pxl(game, pos, map_x, map_y);
	}
}

void	init_minimap(t_game *game)
{
	int	win_y;
	int	map_y;
	int	pos[2];

	win_y = -1;
	map_y = -1;
	while (++win_y < 11)
	{
		map_y = (int)game->player->y / 64 - 5 + win_y;
		if (map_y < 0)
			continue ;
		if (!game->map[map_y])
			break ;
		draw_map_line(game, map_y, win_y);
	}
	pos[0] = 5 * SQUARE;
	pos[1] = 5 * SQUARE;
	draw_square(game->win_tex, pos, 255 * 256);
}
