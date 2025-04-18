/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:11 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/18 15:49:01 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	edit_direction(t_game *game)
{
	int	x;
	int	y;

	if (game->player->l_move)
		game->player->direction -= 0.06;
	if (game->player->r_move)
		game->player->direction += 0.06;
	if (!game->handle_mouse)
		return ;
	mlx_mouse_get_pos(game->mlx_ptr, game->win_ptr, &x, &y);
	if (x != game->width / 2 || y != game->height / 2)
	{
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, game->width / 2, game->height / 2);
		game->player->direction -= ((double)game->width / 2 - x) * 0.001;
	}
}

void	move_player(int key, t_game *game)
{
	double	angle;
	double	tmp_x;
	double	tmp_y;

	angle = get_angle(game->player->direction, key);
	tmp_x = game->player->x + cos(angle) * 6;
	tmp_y = game->player->y + sin(angle) * 6;
	if (!is_wall(game->map, tmp_x, game->player->y))
		game->player->x = tmp_x;
	else if (roundf(game->player->x / 64 - (int)game->player->x / 64))
		game->player->x = roundf(game->player->x / 64) * 64 - 0.5;
	else
		game->player->x = roundf(game->player->x / 64) * 64 + 0.5;
	if (!is_wall(game->map, game->player->x, tmp_y))
		game->player->y = tmp_y;
	else if (roundf(game->player->y / 64 - (int)game->player->y / 64))
		game->player->y = (roundf(game->player->y / 64)) * 64 - 0.5;
	else
		game->player->y = roundf(game->player->y / 64) * 64 + 0.5;
}

int	new_render(void)
{
	static struct timeval	old;
	struct timeval			current;

	if (old.tv_sec == 0)
	{
		gettimeofday(&old, NULL);
		return (1);
	}
	gettimeofday(&current, NULL);
	if (current.tv_sec * 1000 + current.tv_usec / 1000
		> old.tv_sec * 1000 + old.tv_usec / 1000 + 37)
	{
		old = current;
		return (1);
	}
	return (0);
}

void	check_move(t_game *game)
{
	if (game->player->w_move)
		move_player(KEY_W, game);
	if (game->player->a_move)
		move_player(KEY_A, game);
	if (game->player->s_move)
		move_player(KEY_S, game);
	if (game->player->d_move)
		move_player(KEY_D, game);
}

int	ft_render(t_game *game)
{
	if (new_render())
	{
		edit_direction(game);
		if (can_access(game->player->x / 64, game->player->y / 64, game->map)
			&& !is_wall(game->map, game->player->x, game->player->y))
			ft_raycast(game);
		check_move(game);
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->win_tex->img_ptr, 0, 0);
		mlx_destroy_image(game->mlx_ptr, game->win_tex->img_ptr);
		free(game->win_tex);
		ft_init_add(game);
	}
	return (0);
}
