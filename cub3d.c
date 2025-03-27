#include "cub3d.h"
#include <libft/libft.h>
#include <mlx_linux/mlx.h>
#include <stdio.h>

int	ft_isitcub(char *str)
{
	int	i;
	int j;
	char cub[3] = "cub";

	i = 0;
	j = -1;
	while(str[i])
	{
		if(i > 0 && str[i] == '.')
		{
			i++;
			while(str[i] && str[i] == cub[++j])
				++i;
			if(j != 2)
				return (1);
		}
		else
			i++;
	}
	if(j == 2 && str[i - 4] == '.')
		return (0);
	else
		return (1);
}

void	ft_cub3d(char *str)
{
	(void) str;
	t_game game;

	ft_init_mlx(&game);
	ft_init_addr(&game);
	ft_init_ray(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, ft_keypress, &game);
	mlx_hook(game.win_ptr, KeyRelease, KeyReleaseMask, ft_keyrelease, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, ft_closegame, &game);
	mlx_loop_hook(game.win_ptr, ft_rendermap, &game);
	mlx_loop(game.mlx_ptr);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		rows;

	if(ac != 2)
		return (1);	//error_msg();
	//if(ft_isitcub(av[1]) == 1)
		//return (2); //error_msg();
	rows = get_row_size(av[1]);
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
	printf("Sucessfully parsed the config\n");
	//error_msg
//	ft_cub3d(av[1]);
	return (destroy(game, 0));
}

//https://harm-smits.github.io/42docs/projects/cub3d

// int	flood_fill(char **tmp, int x, int y, char c)
// {
// 	int	up;
// 	int	down;
// 	int	right;
// 	int	left;

// 	if (tmp[x][y] == 'X' || tmp[x][y] == '1')
// 		return (0);
// 	if (tmp[x][y] != '1')
// 		tmp[x][y] = 'X';
// 	right = flood_fill(tmp, x, y + 1, c);
// 	up = flood_fill(tmp, x - 1, y, c);
// 	down = flood_fill(tmp, x + 1, y, c);
// 	left = flood_fill(tmp, x, y - 1, c);
// 	if (right == 1 || up == 1 || down == 1 || left == 1)
// 		return (1);
// 	if (tmp[x][y] == c)
// 		return (1);
// 	return (0);
// }
