#include "../cub3d.h"

void	free_images(void *mlx, t_img *img)
{
	mlx_destroy_image(mlx, img->img_ptr);
	free(img);
}

int	ft_closegame(t_game *game)
{
	if (game->images && game->images->no)
		free_images(game->mlx_ptr, game->images->no);
	if (game->images && game->images->so)
		free_images(game->mlx_ptr, game->images->so);
	if (game->images && game->images->ea)
		free_images(game->mlx_ptr, game->images->ea);
	if (game->images && game->images->we)
		free_images(game->mlx_ptr, game->images->we);
	if (game->win_tex.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->win_tex.img_ptr);
	if (game->win_c.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->win_c.img_ptr);
	if (game->win_g.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->win_g.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
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
	char	*line;

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
		return (to_return);
	end_file(game->config);
	if (game->config > 2)
		close(game->config);
	if (game->images && game->images->sky)
		free(game->images->sky);
	if (game->images && game->images->ground)
		free(game->images->ground);
	ft_closegame(game);
	if (game->images)
		free(game->images);
	if (game->player)
		free(game->player);
	destroy_map(game);
	free(game);
	return (to_return);
}
