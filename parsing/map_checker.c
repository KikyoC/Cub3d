#include "../cub3d.h"

static t_point *get_other_point(t_point *point, t_row *row)
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

static void print_line(t_row *row)
{
	t_point	*point;

	point = row->first;
	while (point)
	{
		printf("%c", point->c);
		point = point->next;
	}
	printf("\n");
}

int	is_empty(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int is_point_valid(t_point *point)
{
	t_point	*tmp;

	printf("	-Actual point is %c %p\n", point->c, point);
	if (is_empty(point->c))
	{
		tmp = get_other_point(point, point->row->prev);
		if (!tmp || ft_isspace(tmp->c))
			return (0);
		tmp = get_other_point(point, point->row->next);
		if (!tmp || ft_isspace(tmp->c))
			return (0);
		if (!point->next || (!is_empty(point->next->c) && point->next->c != '1'))
			return (0);
		if (!point->prev || (!is_empty(point->prev->c) && point->prev->c != '1'))
			return (0);
	}
	else if (ft_isspace(point->c))
	{
		tmp = get_other_point(point, point->row->prev);
		if (tmp && tmp->c == 0)
			return (0);
		tmp = get_other_point(point, point->row->next);
		if (tmp && tmp->c == 0)
			return (0);
		//Idk if I have to check prev and next point
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
		printf("Checking line: ");
		print_line(row);
		current = row->first;
		while (current)
		{
			if (!is_point_valid(current))
			{
				printf("Map is not valid\n");
				return (0);
			}
			current = current->next;
		}
		row = row->next;
	}
	printf("Map is valid\n");
	return (1);
}
