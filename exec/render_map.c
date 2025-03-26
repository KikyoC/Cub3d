#include "../cub3d.h"

int	ft_rendermap(t_game *game)
{
	int update;

	update = 0;
	if (game->move.x)
		update = move_camera(game, game->move.x);
	else if(game->move.y)
		update = move_camera(game, game->move.y);
	if (game->x_move.x)
		update = move_strafe_camera(game, game->x_move.x);
	else if(game->x_move.y)
		update = move_strafe_camera(game, game->x_move.y);
	if (game->rotate.x)
		update = rotate_camera(game, game->rotate.x);
	else if(game->rotate.y)
		update = rotate_camera(game,game->rotate.y);
	if(update)
	{
		update_screen(game);
		update_window(game);
	}
	return(0);
}
