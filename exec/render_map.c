#include "../cub3d.h"

int	ft_rendermap(t_game *game)
{
	// check_move(game);
	ft_raycast(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->win_tex.img_ptr, 0, 0);
	return (0);
}
