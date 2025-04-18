/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:36 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/18 16:30:08 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player->w_move = 1;
	else if (keycode == KEY_A)
		game->player->a_move = 1;
	else if (keycode == KEY_S)
		game->player->s_move = 1;
	else if (keycode == KEY_D)
		game->player->d_move = 1;
	else if (keycode == KEY_LEFT)
		game->player->l_move = 1;
	else if (keycode == KEY_RIGHT)
		game->player->r_move = 1;
	else if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx_ptr);
	else if (keycode == KEY_M && game->handle_mouse)
		game->handle_mouse = 0;
	else if (keycode == KEY_M && !game->handle_mouse)
		game->handle_mouse = 1;
	return (0);
}

int	ft_release(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		player->w_move = 0;
	else if (keycode == KEY_A)
		player->a_move = 0;
	else if (keycode == KEY_S)
		player->s_move = 0;
	else if (keycode == KEY_D)
		player->d_move = 0;
	else if (keycode == KEY_LEFT)
		player->l_move = 0;
	else if (keycode == KEY_RIGHT)
		player->r_move = 0;
	return (0);
}
