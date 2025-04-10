#include "../cub3d.h"

static void	print_error(char c, char *line)
{
	ft_putstr_fd("Error\nUnknown charater \"", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\" found on line \"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\"\n", 2);
}

int	add_to_row(char c, t_point **row, char *line)
{
	t_point	*point;
	int		i;

	if (c != '0' && c != '1' && c != 'N'
		&& c != 'S' && c != 'E' && c != 'W'
		&& !ft_isspace(c))
	{
		print_error(c, line);
		return (1);
	}
	point = ft_calloc(1, sizeof(t_point));
	if (!point)
		return (1);
	point->c = c;
	i = 0;
	while (row[i])
		i++;
	row[i] = point;
	return (0);
}

int	parse_line(t_game *game, char *line, int *map)
{
	t_point		**row;
	size_t		len;
	size_t		i;
	static int	to_add;

	i = 0;
	*map = 1;
	len = ft_strlen(line);
	row = ft_calloc(len + 1, sizeof(t_point *));
	if (!row)
		return (1);
	while (i < len)
	{
		if (add_to_row(line[i], row, line))
		{
			destroy_row(row);
			return (1);
		}
		i++;
	}
	i = 0;
	game->map[to_add] = row;
	to_add ++;
	return (0);
}
