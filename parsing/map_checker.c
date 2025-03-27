#include "../cub3d.h"

int	is_empty(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

t_point *get_other_point(t_point ***map, int x, int y, int rows)
{
	if (y + rows < 0)
		return (NULL);
	return (map[y + rows][x]);
}

static int	is_point_valid(t_point ***map, int x, int y)
{
	t_point	*tmp;

	if (is_empty(map[y][x]->c))
	{
		tmp = get_other_point(map, x , y, -1);
		if (!tmp || ft_isspace(tmp->c))
			return (0);
		tmp = get_other_point(map, x, y, 1);
		if (!tmp || ft_isspace(tmp->c))
			return (0);
		if (!map[y][x] || (!is_empty(map[y][x + 1]->c) && map[y][x + 1]->c != '1'))
			return (0);
		if (!map[y][x - 1] || (!is_empty(map[y][x - 1]->c) && map[y][x - 1]->c != '1'))
			return (0);
	}
	else if (ft_isspace(map[y][x]->c))
	{
		tmp = get_other_point(map, x, y, -1);
		if (tmp && tmp->c == 0)
			return (0);
		tmp = get_other_point(map, x, y, 1);
		if (tmp && tmp->c == 0)
			return (0);
	}
	return (1);
}

static void	print_line(t_point **row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		ft_putchar_fd(row[i]->c, 2);
		i++;
	}
}

int	is_map_valid(t_game *game)
{
	int		row;
	int		point;

	row = 0;
	while (game->map[row])
	{
		point = 0;
		while (game->map[row][point])
		{
			if (!is_point_valid(game->map, point, row))
			{
				ft_putstr_fd("Error\nMap error on line \"", 2);
				print_line(game->map[row]);
				ft_putstr_fd("\"\n", 2);
				return (0);
			}
			point ++;
		}
		row ++;
	}
	return (1);
}
