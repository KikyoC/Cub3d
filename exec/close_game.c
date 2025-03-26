#include "../cub3d.h"

int	ft_closegame(t_game *game)
{
	//mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr); | 4 image au total
	//mlx_destroy_image(game->mlx_ptr, game->ceiling.mlx_img);
	mlx_destroy_image(game->mlx_ptr, game->win_tex.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->win_g.img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->win_c.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}