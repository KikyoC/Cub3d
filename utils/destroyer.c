#include "../cub3d.h"

void	ft_closegame(t_game *game)
{
	//mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr); | 4 image au total
	//mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
}

void	destroy_row(t_row *row)
{
	t_point	*current;
	t_point *next;

	current = row->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(row);
}


void	destroy_map(t_game *game)
{
	t_row	*current;
	t_row	*next;

	current = game->first;
	while (current)
	{
		next = current->next;
		destroy_row(current);
		current = next;
	}
	if (game->player)
		free(game->player);
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
		return (to_return);
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
	if (game->mlx_ptr)
		ft_closegame(game);
	destroy_map(game);
	free(game);
	return (to_return);
}
