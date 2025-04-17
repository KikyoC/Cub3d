/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:05:23 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 10:19:41 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isitcub(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (str[i])
	{
		if (i > 0 && str[i] == '.')
		{
			i++;
			while (str[i] && str[i] == EXTENSION[++j])
				++i;
			if (j != 2)
				return (1);
		}
		else
			i++;
	}
	if (j == 2 && str[i - 4] == '.')
		return (0);
	else
		return (1);
}

void	ft_cub3d(t_game *game)
{
	ft_init_mlx(game);
	ft_init_add(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, ft_press, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask,
		ft_release, game->player);
	mlx_hook(game->win_ptr, DestroyNotify, 0, mlx_loop_end, game->mlx_ptr);
	mlx_loop_hook(game->mlx_ptr, ft_render, game);
	mlx_loop(game->mlx_ptr);
}

static void	ft_error_main(int flag)
{
	ft_putendl_fd("Error", 2);
	if (flag == 1)
		ft_putendl_fd("Not enough or too many arguments", 2);
	else if (flag == 2)
		ft_putendl_fd("Is it *.cub ?", 2);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		rows;

	if (ac != 2)
		ft_error_main(1);
	if (ft_isitcub(av[1]) == 1)
		ft_error_main(2);
	rows = get_row_size(av[1]);
	printf("Coucou c moi tchoupi\n");
	if (rows < 0)
	{
		ft_putstr_fd("Error\nCannot open the config\n", 2);
		return (1);
	}
	game = ft_calloc(1, sizeof(t_game));
	game->mlx_ptr = mlx_init();
	if (!game)
		return (1);
	game->map = ft_calloc(rows + 1, sizeof(t_point **));
	if (!game->map || parse(game, av[1]))
		return (destroy(game, 1));
	ft_cub3d(game);
	return (destroy(game, 0));
}
