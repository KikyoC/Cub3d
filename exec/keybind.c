#include "../cub3d.h"

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
