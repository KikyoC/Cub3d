#include "../cub3d.h"

static void	set_file(t_game *game, int file, char c)
{
	if (c == 'N' && game->no == 0)
		game->no = file;
	else if (c == 'S' && game->so == 0)
		game->so = file;
	else if (c == 'E' && game->ea == 0)
		game->ea = file;
	else if (c == 'W' && game->we == 0)
		game->we = file;
}

static int	print_error(int type, char *line, int to_return)
{
	if (type == 1)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(" on line \"", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\"\n", 2);
	}
	else
	{
		ft_putstr_fd("Duplicated texture on line \"", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\"\n", 2);
	}
	return (to_return);
}

/*
 * Return 0 on success 1 on failure 2 on duplication
*/
int	open_texture(t_game *game, char *line)
{
	int		file;
	int		i;
	char	c;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	c = line[i];
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	file = open(&line[i], O_RDONLY);
	if (file < 3)
		return (print_error(1, line, 1));
	set_file(game, file, c);
	if (game->no != file && game->so != file
		&& game->ea != file && game->we != file)
	{
		close(file);
		return (print_error(2, line, -2));
	}
	return (0);
}
