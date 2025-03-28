#include "../cub3d.h"

int	ft_closegame(t_game *game)
{
	//mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr); | 4 image au total
	//mlx_destroy_image(game->mlx_ptr, game->ceiling.mlx_img);
	// if (game->win_tex.img_ptr)
	// 	mlx_destroy_image(game->mlx_ptr, game->win_tex.img_ptr);
	// if (game->win_g.img_ptr)
	// 	mlx_destroy_image(game->mlx_ptr, game->win_g.img_ptr);	
	// if (game->win_c.img_ptr)
	// 	mlx_destroy_image(game->mlx_ptr, game->win_c.img_ptr);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	// exit(0);
	return (0);
}

void	destroy_row(t_point **row)
{
	size_t	i;

	i = 0;
	while (row[i])
	{
		free(row[i]);
		i++;
	}
}

void	destroy_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game && game->map && game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			free(game->map[y][x]);
			x++;
		}
		free(game->map[y]);
		y++;
	}
	if (game && game->map)
		free(game->map);
}

void	end_file(int config)
{
	char *line;

	if (config < 3)
		return ;
	line = get_next_line(config);
	while (line)
	{
		free(line);
		line = get_next_line(config);
	}
}

int	destroy(t_game *game, int to_return)
{
	if (!game)
	{
		return (to_return);
	}
	end_file(game->config);
	if (game->config > 2)
		close(game->config);
	if (game->images && game->images->no)
		mlx_destroy_image(game->mlx_ptr, game->images->no);
	if (game->images && game->images->so)
		mlx_destroy_image( game->mlx_ptr, game->images->so);
	if (game->images && game->images->ea)
		mlx_destroy_image(game->mlx_ptr, game->images->ea);
	if (game->images && game->images->we)
		mlx_destroy_image(game->mlx_ptr, game->images->we);
	if (game->images && game->images->sky)
		free(game->images->sky);
	if (game->images && game->images->ground)
		free(game->images->ground);
	if (game->images)
		free(game->images);
	// if (game->mlx_ptr)
		// ft_closegame(game);
	// if (game->player)
		// free(game->player);
	destroy_map(game);
	if (game)
		free(game);
	return (to_return);
}
