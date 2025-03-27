#include "../cub3d.h"

void	move_player(int keysym, t_game *game)
{
	char **map;
	float	angle;
	float ray_cos;
	float ray_sin;

	map = (char **)game->map;
	if (keysym == KEY_A)
		angle = game->ray.angle - 90;
	else if (keysym == KEY_S)
		angle = game->ray.angle - 180;
	else if (keysym == KEY_D)
		angle = game->ray.angle + 90;
	else
		angle = game->ray.angle;
	ray_cos = cos(degree_to_radians(angle));
	ray_sin = sin(degree_to_radians(angle));
	if (!ft_strchr("1", map[(int)(game->player->y + 0.5 + \
		(3 * ray_sin))][(int)(game->player->x + 0.5)]))
		game->player->y += ray_sin;
	if (!ft_strchr("1", map[(int)(game->player->y + 0.5)] \
		[(int)(game->player->x + 0.5 + (3 * ray_cos))]))
		game->player->x += ray_cos;
}

void	check_move(t_game *game)
{
	if (game->player->l_move)
		game->ray.angle -= 3;
	if (game->player->r_move)
		game->ray.angle += 3;
	if (game->player->w_move)
		move_player(KEY_W, game);
	if (game->player->a_move)
		move_player(KEY_A, game);
	if (game->player->s_move)
		move_player(KEY_S, game);
	if (game->player->d_move)
		move_player(KEY_D, game);
}

int	ft_keypress(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->player->w_move = 1;
	if (keysym == KEY_S)
		game->player->s_move = 1;
	if (keysym == KEY_A)
		game->player->a_move = 1;
	if (keysym == KEY_D)
		game->player->d_move = 1;
	if (keysym == KEY_LEFT)
		game->player->l_move = 1;
	if (keysym == KEY_RIGHT)
		game->player->r_move = 1;
	return (0);
}

int ft_keyrelease(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->player->w_move = 0;
	if (keysym == KEY_S)
		game->player->s_move = 0;
	if (keysym == KEY_A)
		game->player->a_move = 0;
	if (keysym == KEY_D)
		game->player->d_move = 0;
	if (keysym == KEY_LEFT)
		game->player->l_move = 0;
	if (keysym == KEY_RIGHT)
		game->player->r_move = 0;
	if (keysym == KEY_ESC)
		ft_closegame(game);
	return (0);
}
