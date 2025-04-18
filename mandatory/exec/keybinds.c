/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huvillat <huvillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:36 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 16:30:16 by huvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	ft_windsize(t_game *game, int size)
{
	t_win_list *win;
	t_xvar	*xvar;

	win = game->win_ptr;
	xvar = game->mlx_ptr;
	if(size == 1)
	{
		mlx_int_anti_resize_win(xvar, win->window, game->width - 100, game->height + 100);
		game->inc--;
		game->dec++;
		game->width = game->width - 100;
		game->height = game->height + 100;
	}
	else if (size == -1)
	{
		mlx_int_anti_resize_win(xvar, win->window, game->width - 100, game->height - 100);
		game->dec--;
		game->inc++;
		game->width -= 100;
		game->height -= 100;
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
