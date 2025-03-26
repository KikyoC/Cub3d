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

int	parse_walls(t_game *game)
{
	char	*line;
	int		type;
	int		error;

	line = get_next_line(game->config);
	error = 0;
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		type = get_line_type(line);
		if (type == 1 && open_texture(game, line))
			error = 1;
		else if (type == 2 && parse_color(game, line))
			error = 1;
		else if (type == 3 && parse_line(game, line))
			error = 1;
		free(line);
		if (error)
			return (1);
		line = get_next_line(game->config);
	}
	return (0);
}

int	startings_positions(t_game *game)
{
	t_row	*row;
	t_point	*point;
	int		res;

	res = 0;
	row = game->first;
	while (row)
	{
		point = row->first;
		while (point)
		{
			if (point->c == 'N' || point->c == 'S'
				|| point->c == 'E' || point->c == 'W')
				res++;
			point = point->next;
		}
		row = row->next;
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
	if (!game->so)
		ft_putstr_fd(S_TEXTURE, 2);
	if (!game->no)
		ft_putstr_fd(N_TEXTURE, 2);
	if (!game->ea)
		ft_putstr_fd(E_TEXTURE, 2);
	if (!game->we)
		ft_putstr_fd(W_TEXTURE, 2);
	if (!game->ground)
		ft_putstr_fd(GROUND, 2);
	if (!game->sky)
		ft_putstr_fd(SKY, 2);
	if (game->first == NULL)
		ft_putstr_fd(MAP, 2);
	if (startings_positions(game) != 1)
		ft_putstr_fd(POS, 2);
	return (game->so || game->no || game->ea
		|| game->we || !game->ground || !game->sky
		|| startings_positions(game) != 1 || game->first == NULL);
}
