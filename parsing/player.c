#include "../cub3d.h"

t_point	*get_player_pos(t_point ***map, double *x, double *y)
{
	*y = 0.5;
	while (map[(int)*y])
	{
		*x = 0.5;
		while (map[(int)*y][(int)*x])
		{
			if (map[(int)*y][(int)*x]->c == 'N' ||
				map[(int)*y][(int)*x]->c == 'S' \
				|| map[(int)*y][(int)*x]->c == 'E' || \
				map[(int)*y][(int)*x]->c == 'W')
				return (map[(int)*y][(int)*x]);
			*x += 1;
		}
		*y += 1;
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
	game->player->point = get_player_pos(game->map, \
		&game->player->x, &game->player->y);
	if (!game->player->point)
		return (1);
	if (game->player->point->c == 'N')
		game->player->direction = 270;
	else if (game->player->point->c == 'E')
		game->player->direction = 0;
	else if (game->player->point->c == 'S')
		game->player->direction = 90;
	else if (game->player->point->c == 'W')
		game->player->direction = 180;
	game->player->direction = M_PI / 2;
	game->player->x = 640;
	game->player->y = 516;
	return (0);
}
