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
	x / 2, y / 2, "Cub3D");
	game->height = y / 2;
	game->width = x / 2;
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		//ft_error_msg("Couldn't create the window.", game);
	}
}

t_pos ft_init_vector(int x, int y)
{
	t_pos vector;
	vector.x = x;
	vector.y = y;
	return(vector);
}

void	ft_init_add(t_game *game)
{
	// texture
	game->win_tex.img_ptr = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->win_tex.addr = mlx_get_data_addr(game->win_tex.img_ptr, &game->win_tex.bpp, \
		&game->win_tex.line_len, &game->win_tex.endian);
	//ground
	game->win_g.img_ptr = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->win_g.addr = mlx_get_data_addr(game->win_g.img_ptr, &game->win_g.bpp, &game->win_g.line_len, &game->win_g.endian);
	mlx_area_put(&game->win_g, ft_init_vector(0, 0), ft_init_vector(game->width, game->height), generate_color(game->images->ground[0], game->images->ground[1], game->images->ground[2]));
	//ceilling
	game->win_c.img_ptr = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->win_c.addr = mlx_get_data_addr(game->win_c.img_ptr, &game->win_c.bpp, &game->win_c.line_len, &game->win_c.endian);                                                    
	mlx_area_put(&game->win_c, ft_init_vector(0, 0), ft_init_vector(game->width, game->height), generate_color(game->images->sky[0], game->images->sky[1], game->images->sky[2]));
}
