#include "../cub3d.h"

void	edit_direction(t_player *player)
{
	if (player->l_move)
		player->direction -= 3;
	if (player->r_move)
		player->direction += 3;
	while (player->l_move > 360)
		player->l_move -= 360;
	while (player->r_move < 0)
		player->r_move += 360;

}

void ft_black(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			mlx_put_pixel(game->win_tex, x, y, generate_color(0, 255, 0));
			x++;
		}
		y++;
	}
}

int	ft_render(t_game *game)
{
	edit_direction(game->player);
	ft_raycast(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->win_tex->img_ptr, 0, 0);
	mlx_destroy_image(game->mlx_ptr, game->win_tex->img_ptr);
	free(game->win_tex);
	ft_init_add(game);
	return (0);
}
