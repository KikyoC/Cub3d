#include "../cub3d.h"

static void	print_error(char c, char *line)
{
	ft_putstr_fd("Unknown charater \"", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\" found on line \"", 2);
	ft_putstr_fd(line, 2);
	ft_putstr_fd("\"\n", 2);
}

int	add_to_row(char c, t_row *row, char *line)
{
	t_point	*point;
	t_point	*current;

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
	point->row = row;
	current = row->first;
	while (current && current->next)
		current = current->next;
	if (current)
		current->next = point;
	else
		row->first = point;
	point->prev = current;
	return (0);
}

int	parse_line(t_game *game, char *line)
{
	t_row	*row;
	t_row	*current;
	int		i;

	row = ft_calloc(1, sizeof(t_row));
	if (!row)
		return (1);
	i = -1;
	while (line[++i])
	{
		if (add_to_row(line[i], row, line))	
		{
			destroy_row(row);
			return (1);
		}
	}
	current = game->first;
	while (current && current->next)
		current = current->next;
	if (current)
		current->next = row;
	else
		game->first = row;
	row->prev = current;
	return (0);
}
