#include "../cub3d.h"

int	ft_render(t_game *game)
{
	ft_raycast(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->win_tex->img_ptr, 0, 0);
	printf("-------------------------\n");
	//mlx_loop_end(game->mlx_ptr);
	return (0);
}
