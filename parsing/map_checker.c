#include "../cub3d.h"

static t_point	*get_other_point(t_point *point, t_row *row)
{
	t_point	*current;
	int		i;

	if (!row)
		return (NULL);
	current = point->row->first;
	i = 0;
	while (current != point)
	{
		current = current->next;
		i++;
	}
	current = row->first;
	while (i > 0)
	{
		current = current->next;
		if (!current)
			return (NULL);
		i--;
	}
	return (current);
}

static void	print_line(t_row *row)
{
	t_point	*point;

	point = row->first;
	while (point)
	{
		ft_putchar_fd(point->c, 2);
		point = point->next;
	}
}

int	is_empty(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_point_valid(t_point *p)
{
	t_point	*tmp;

	if (is_empty(p->c))
	{
		tmp = get_other_point(p, p->row->prev);
		if (!tmp || ft_isspace(tmp->c))
			return (0);
		tmp = get_other_point(p, p->row->next);
		if (!tmp || ft_isspace(tmp->c))
			return (0);
		if (!p->next || (!is_empty(p->next->c) && p->next->c != '1'))
			return (0);
		if (!p->prev || (!is_empty(p->prev->c) && p->prev->c != '1'))
			return (0);
	}
	else if (ft_isspace(p->c))
	{
		tmp = get_other_point(p, p->row->prev);
		if (tmp && tmp->c == 0)
			return (0);
		tmp = get_other_point(p, p->row->next);
		if (tmp && tmp->c == 0)
			return (0);
	}
	return (1);
}

int	is_map_valid(t_game *game)
{
	t_point	*current;
	t_row	*row;

	row = game->first;
	while (row)
	{
		current = row->first;
		while (current)
		{
			if (!is_point_valid(current))
			{
				ft_putstr_fd("Map error on line \"", 2);
				print_line(row);
				ft_putstr_fd("\"\n", 2);
				return (0);
			}
			current = current->next;
		}
		row = row->next;
	}
	return (1);
}
