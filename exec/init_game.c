#include "../cub3d.h"

void	ft_init_mlx(t_game *game)
{
	int x;
	int y;

	y = 0;
	x = 0;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		//ft_error_msg("Couldn't find mlx pointer.", game);
	}
	mlx_get_screen_size(game->mlx_ptr, &x, &y);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	x / 2, y / 2, "cub3d");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		//ft_error_msg("Couldn't create the window.", game);
	}
}
