#include "../cub3d.h"

void	move_player(int keysym, t_game *game)
{
	float	angle;
	float ray_cos;
	float ray_sin;

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

}

void	check_move(t_game *game)
{
	if (game->play.l_move)
		game->ray.angle -= 3;
	if (game->play.r_move)
		game->ray.angle += 3;
	if (game->play.w_move)
		move_player(KEY_W, game);
	if (game->play.a_move)
		move_player(KEY_A, game);
	if (game->play.s_move)
		move_player(KEY_S, game);
	if (game->play.d_move)
		move_player(KEY_D, game);
}

int	ft_keypress(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->play.w_move = 1;
	if (keysym == KEY_S)
		game->play.s_move = 1;
	if (keysym == KEY_A)
		game->play.a_move = 1;
	if (keysym == KEY_D)
		game->play.d_move = 1;
	if (keysym == KEY_LEFT)
		game->play.l_move = 1;
	if (keysym == KEY_RIGHT)
		game->play.r_move = 1;
	return (0);
}

int ft_keyrelease(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->play.w_move = 0;
	if (keysym == KEY_S)
		game->play.s_move = 0;
	if (keysym == KEY_A)
		game->play.a_move = 0;
	if (keysym == KEY_D)
		game->play.d_move = 0;
	if (keysym == KEY_LEFT)
		game->play.l_move = 0;
	if (keysym == KEY_RIGHT)
		game->play.r_move = 0;
	if (keysym == KEY_ESC)
		ft_closegame(game);
}
