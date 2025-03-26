#include "../cub3d.h"

int	ft_keypress(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->move.x = 1;
	if (keysym == KEY_S)
		game->move.y = 1;
	if (keysym == KEY_A)
		game->x_move.x = 1;
	if (keysym == KEY_D)
		game->x_move.y = 1;
	if (keysym == KEY_LEFT)
		game->rotate.x = 1;
	if (keysym == KEY_RIGHT)
		game->rotate.y = 1;
	return (0);
}

int ft_keyrelease(int keysym, t_game *game)
{
	if (keysym == KEY_W)
		game->move.x = 0;
	if (keysym == KEY_S)
		game->move.y = 0;
	if (keysym == KEY_A)
		game->x_move.x = 0;
	if (keysym == KEY_D)
		game->x_move.y = 0;
	if (keysym == KEY_LEFT)
		game->rotate.x = 0;
	if (keysym == KEY_RIGHT)
		game->rotate.y = 0;
	if (keysym == KEY_ESC)
		ft_closegame(game);
}
