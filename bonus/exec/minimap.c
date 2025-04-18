/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:42:21 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 18:11:16 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void draw(t_game *game, int pos[2], int max[2])
{
	int	*color;
	int	x;
	int	y;

	x = (int)game->player->x / 64 - 3 + pos[0] / SQUARE;
	y = (int)game->player->y / 64 - 3 + pos[1] / SQUARE;
	color = generate_color(255, 0, 0);
	if (x < 0 || y < 0 || x >= max[0] || y >= max[1])
		return ;
	printf("Trying to access (%i,%i) with max (%i,%i)\n", x, y, max[x], max[y]);
	if (game->map
		[y]
		[x] && game->map
		[y]
		[x]->c == '1')
		draw_square(game->win_tex, pos, *color);
	else
		draw_square(game->win_tex, pos, 0);
	free(color);
}

void	draw_map(t_game *game, int max[2])
{
	int	x;
	int	y;
	int	pos[2];

	y = -1;
	while (++y < max[1] && y < 7)
	{
		x = -1;
		max[0] = max_x(game->map[y]);
		while (++x < max[0] && x < 7)
		{
			pos[0] = x * SQUARE;
			pos[1] = y * SQUARE;
			draw(game, pos, max);
		}
	}
}

void	init_minimap(t_game *game)
{
	int	pos[2];
	int	max[2];

	max[1] = max_y(game->map);
	draw_map(game, max);
	pos[0] = 3 * SQUARE;
	pos[1] = 3 * SQUARE;
	draw_square(game->win_tex, pos, *generate_color(0, 255, 0));
}
