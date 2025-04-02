#include "../cub3d.h"

int	is_in_wall(float x, float y, float ray_angle, t_point ***map)
{
	int	a_x;
	int a_y;

	a_x = x;
	a_y = y;
	if (ray_angle < 3)
	{
		a_x += 1;
		a_y += 1;
	}

	return (map[a_y][a_x]->c == '1' || map[a_y][a_x]->c == '\0');
}

void	move_player(int keysym, t_game *game)
{
	float	angle;
	float ray_cos;
	float ray_sin;

	if (keysym == KEY_S)
		angle = game->ray.angle - 180;
	else if (keysym == KEY_D)
		angle = game->ray.angle + 90;
	else if (keysym == KEY_A)
		angle = game->ray.angle - 90;
	else
		angle = game->ray.angle;
	while (angle > 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	angle = angle * (M_PI / 180.0);
	ray_cos = cos(angle);
	ray_sin = sin(angle);
		game->player->x += ray_cos * 0.1;
		game->player->y += ray_sin * 0.1;
	//printf("Ray_angle = %f. Player position: x = %f ray_cos = %f, y = %f ray_sin = %f\n", angle, game->player->x, ray_cos, game->player->y, ray_cos);
}

void	check_move(t_game *game)
{
	if (game->player->l_move)
		game->ray.angle -= 3;
	if (game->player->r_move)
		game->ray.angle += 3;
	while (game->ray.angle > 360)
		game->ray.angle -= 360;
	while (game->ray.angle < 0)
		game->ray.angle += 360;
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
		mlx_loop_end(game->mlx_ptr);
	return (0);
}
