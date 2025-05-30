/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:05:07 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/16 10:05:48 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_point	*get_player_pos(t_point ***map, double *x, double *y)
{
	t_point	*res;
	int		found;

	found = 0;
	*y = 0.5;
	while (map[(int)*y])
	{
		*x = 0.5;
		while (map[(int)*y][(int)*x])
		{
			if (map[(int)*y][(int)*x]->c == 'N' ||
				map[(int)*y][(int)*x]->c == 'S' \
				|| map[(int)*y][(int)*x]->c == 'E' || \
				map[(int)*y][(int)*x]->c == 'W')
				found = 1;
			if (found)
				break ;
			*x += 1;
		}
		if (found)
			break ;
		*y += 1;
	}
	res = map[(int)*y][(int)*x];
	return (res);
}

int	setup_player(t_game *game)
{
	if (game->player)
		return (0);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return (1);
	game->player->point = get_player_pos(game->map,
			&game->player->x, &game->player->y);
	if (!game->player->point)
		return (1);
	if (game->player->point->c == 'N')
		game->player->direction = 270 * M_PI / 180;
	else if (game->player->point->c == 'E')
		game->player->direction = 0;
	else if (game->player->point->c == 'S')
		game->player->direction = 90 * M_PI / 180;
	else if (game->player->point->c == 'W')
		game->player->direction = 180 * M_PI / 180;
	game->player->x *= 64;
	game->player->y *= 64;
	return (0);
}
