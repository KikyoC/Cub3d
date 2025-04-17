/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huvillat <huvillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:36 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 15:06:00 by huvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_windsize(t_game *game, int size)
{
	mlx_loop_end(game->mlx_ptr);
	
	if(size == 1)
	{
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * 1.5, game->height * 1.5, "Cub3D");
		game->inc--;
		game->dec++;
		game->width *= 1.5;
		game->height *= 1.5;
	}
	else if (size == -1)
	{
		game->win_ptr = mlx_new_window(game->mlx_ptr, game->width / 1.5, game->height / 1.5, "Cub3D");
		game->dec--;
		game->inc++;
		game->width /= 1.5;
		game->height /= 1.5;
	}
}

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
	else if(keycode == KEY_UP && keycode != KEY_DOWN)
	{
		if(game->inc > 0)
			ft_windsize(game, 1);
	}
	else if(keycode == KEY_DOWN && keycode != KEY_UP)
	{
		if(game->dec > 0)
			ft_windsize(game, -1);
	}
	else if (keycode == KEY_ESC)
		mlx_loop_end(game->mlx_ptr);
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
