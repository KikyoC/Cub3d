/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:40 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/16 10:05:47 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
