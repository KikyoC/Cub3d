#include "../cub3d.h"

int	get_line_type(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (((line[i] == 'N' && line[i + 1] == 'O')
			|| (line[i] == 'S' && line[i + 1] == 'O')
			|| (line[i] == 'W' && line[i + 1] == 'E')
			|| (line[i] == 'E' && line[i + 1] == 'A'))
		&& ft_isspace(line[i + 2]))
		return (1);
	else if ((line[i] == 'C' || line[i] == 'F') && ft_isspace(line[i + 1]))
		return (2);
	else if (line[i] == '\0' || line[i] == '\n')
		return (4);
	else
		return (3);
}

int	handle_line(t_game *game, char *line)
{
	int			type;
	int 		error;
	static int	map;

	line[ft_strlen(line) - 1] = '\0';
	type = get_line_type(line);
	error = 0;
	if (type == 1 && (map || open_texture(game->images, game->mlx_ptr, line)))
		error = 1;
	else if (type == 2 && (map || parse_color(game->images, line)))
		error = 1;
	else if (type == 3 && parse_line(game, line, &map))
		error = 1;
	free(line);
	if (error)
		return (1);
	return (0);
}

int	parse_walls(t_game *game)
{
	char	*line;

	game->images = ft_calloc(1, sizeof(t_images));
	if (!game->images)
		return (1);
	line = get_next_line(game->config);
	while (line)
	{
		if (handle_line(game, line))
			return (1);
		line = get_next_line(game->config);
	}
	return (0);
}

int	startings_positions(t_game *game)
{
	int	i;
	int	j;
	int res;

	i = 0;
	res = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j]->c == 'N' || game->map[i][j]->c == 'S'
				|| game->map[i][j]->c == 'E' || game->map[i][j]->c == 'W')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

static int	print_error(char *str, int to_return)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	return (to_return);
}

int	parse(t_game *game, char *filename)
{
	game->config = open(filename, O_RDONLY);
	if (game->config < 3)
		return (print_error(strerror(errno), 1));
	if (parse_walls(game) || !is_map_valid(game))
		return (1);
	if (!game->images->so)
		ft_putstr_fd(S_TEXTURE, 2);
	if (!game->images->no)
		ft_putstr_fd(N_TEXTURE, 2);
	if (!game->images->ea)
		ft_putstr_fd(E_TEXTURE, 2);
	if (!game->images->we)
		ft_putstr_fd(W_TEXTURE, 2);
	if (!game->images->ground)
		ft_putstr_fd(GROUND, 2);
	if (!game->images->sky)
		ft_putstr_fd(SKY, 2);
	if (game->map == NULL)
		ft_putstr_fd(MAP, 2);
	if (startings_positions(game) != 1)
		ft_putstr_fd(POS, 2);
	return (!game->images->so || !game->images->no || !game->images->ea
		|| !game->images->we || !game->images->ground || !game->images->sky
		|| startings_positions(game) != 1 || game->map == NULL
		|| setup_player(game));
}
