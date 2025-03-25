#include "../cub3d.h"
#include <unistd.h>

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
	if (game->no > 2)
		close(game->no);
	if (game->so > 2)
		close(game->so);
	if (game->ea > 2)
		close(game->ea);
	if (game->we > 2)
		close(game->we);
	if (game->sky)
		free(game->sky);
	if (game->ground)
		free(game->ground);
	destroy_map(game);
	free(game);
	return (to_return);
}
