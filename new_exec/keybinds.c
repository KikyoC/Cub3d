#include "../cub3d.h"

void	move_player(int keysym, t_player *player)
{
	float	angle;
	float	ray_cos;
	float	ray_sin;

	if (keysym == KEY_S)
		angle = player->direction - 180;
	else if (keysym == KEY_D)
		angle = player->direction + 90;
	else if (keysym == KEY_A)
		angle = player->direction - 90;
	else if (keysym == KEY_W)
		angle = player->direction;
	else
	 	return ;
	while (angle > 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	angle = angle * (M_PI / 180.0);
	ray_cos = cos(angle);
	ray_sin = sin(angle);
	player->x += ray_cos * 0.1;
	player->y += ray_sin * 0.1;
	printf("Ray_angle = %f. Player position: x = %f ray_cos = %f, \
y = %f ray_sin = %f\n", \
		angle, player->x, ray_cos, player->y, ray_cos);
}

int	ft_press(int keycode, t_game *game)
{
	if(keycode == KEY_W)
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
	move_player(keycode, game->player);
	return (0);
}

int	ft_release(int keycode, t_player *player)
{
	if(keycode == KEY_W)
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
