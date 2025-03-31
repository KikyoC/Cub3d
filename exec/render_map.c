#include "../cub3d.h"

int	ft_rendermap(t_game *game)
{
	// int i = 0;

	// if(i == 0)
	// {
		check_move(game);
		ft_raycast(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->win_tex.img_ptr, 0, 0);
//		i++;
//	}
	return (0);
}
