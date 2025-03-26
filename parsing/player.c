#include "../cub3d.h"

t_point	*get_player_pos(t_row *row)
{
	t_point	*res;

	while (row)
	{
		res = row->first;
		while (res)
		{
			if (res->c == 'N' || res->c == 'S'
				|| res->c == 'E' || res->c == 'W')
				return (res);
			res = res->next;
		}
		row = row->next;
	}
	return (NULL);
}

int	setup_player(t_game *game)
{
	if (game->player)
		return (0);
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->player)
		return (1);
	game->player->point = get_player_pos(game->first);
	if (!game->player->point)
		return (1);
	game->player->x = 0.5;
	game->player->y = 0.5;
	if (game->player->point->c == 'N')
		game->player->direction = 0;
	else if (game->player->point->c == 'E')
		game->player->direction = 90;
	else if (game->player->point->c == 'S')
		game->player->direction = 180;
	else if (game->player->point->c == 'W')
		game->player->direction = 270;
	return (0);
}
