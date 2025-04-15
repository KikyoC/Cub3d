#include "../cub3d.h"

int	is_empty(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

t_point	*get_other_point(t_point ***map, int x, int y, int rows)
{
	int	i;

	i = 0;
	if (y + rows < 0 || !map[y + rows])
		return (NULL);
	while (map[y + rows][i])
	{
		if (i == x)
			return (map[y + rows][x]);
		i++;
	}
	return (NULL);
}

int	empty_check(t_point ***map, int x, int y)
{
	t_point	*tmp;

	if (!map[y][x + 1])
		return (0);
	tmp = get_other_point(map, x, y, -1);
	if (!tmp || ft_isspace(tmp->c))
		return (0);
	tmp = get_other_point(map, x, y, 1);
	if (!tmp || ft_isspace(tmp->c))
		return (0);
	if (!map[y][x] || (!is_empty(map[y][x + 1]->c) && \
	map[y][x + 1]->c != '1'))
		return (0);
	if (!map[y][x - 1] || (!is_empty(map[y][x - 1]->c) \
		&& map[y][x - 1]->c != '1'))
		return (0);
	return (1);
}

int	space_check(t_point ***map, int x, int y)
{
	t_point	*tmp;

	tmp = get_other_point(map, x, y, -1);
	if (tmp && tmp->c == '0')
		return (0);
	tmp = get_other_point(map, x, y, 1);
	if (tmp && tmp->c == '0')
		return (0);
	return (1);
}

int	is_point_valid(t_point ***map, int x, int y)
{
	if (is_empty(map[y][x]->c))
		return (empty_check(map, x, y));
	else if (map[y][x] && ft_isspace(map[y][x]->c))
		return (space_check(map, x, y));
	return (1);
}
