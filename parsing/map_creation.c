/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:41 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/24 11:35:46 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	error(t_point **row, t_game *game)
{
	if (!row)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (1);
	}
	if (!game->images || !game->images->ea
		|| !game->images->we || !game->images->no
		|| !game->images->so || !game->images->ground
		|| !game->images->sky)
	{
		if (row)
			free(row);
		ft_putstr_fd("Cannot parse map while all textures not genrated\n", 2);
		return (1);
	}
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
	if (error(row, game))
		return (1);
	while (i < len)
	{
		if (add_to_row(line[i], row, line))
		{
			destroy_row(row);
			free(row);
			return (1);
		}
		i++;
	}
	i = 0;
	game->map[to_add] = row;
	to_add ++;
	return (0);
}
