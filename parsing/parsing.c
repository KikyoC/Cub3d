#include "../cub3d.h"
#include <fcntl.h>
#include <string.h>

/*
* Return type. 1 is wall texture, 2 is sky or ground color, 3 is a map line, 4 is empty line, 0 is unknown
*/
int get_line_type(char *line)
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

int parse_walls(t_game *game)
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

int parse(t_game *game, char *filename)
{
	game->config = open(filename, O_RDONLY);
	if (game->config < 3)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (1);
	}
	return (parse_walls(game) || !is_map_valid(game));
}
