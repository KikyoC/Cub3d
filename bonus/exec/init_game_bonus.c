/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huvillat <huvillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:37 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 16:01:11 by huvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_init_mlx(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	mlx_get_screen_size(game->mlx_ptr, &x, &y);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	x / 2, y / 2, "Cub3D");
	game->height = y / 2;
	game->width = x / 2;
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		printf("ERROR\nCannot open window");
	}
}

void	ft_init_add(t_game *game)
{
	game->win_tex = ft_calloc(1, sizeof(t_texture));
	game->win_tex->img_ptr = mlx_new_image(game->mlx_ptr,
			game->width, game->height);
	game->win_tex->addr = mlx_get_data_addr(game->win_tex->img_ptr,
			&game->win_tex->bpp, &game->win_tex->line_len,
			&game->win_tex->endian);
}
