#include "../cub3d.h"

static void	set_file(t_images *images, void *file, char c)
{
	if (c == 'N' && images->no == 0)
		images->no = file;
	else if (c == 'S' && images->so == 0)
		images->so = file;
	else if (c == 'E' && images->ea == 0)
		images->ea = file;
	else if (c == 'W' && images->we == 0)
		images->we = file;
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
int	open_texture(t_images *images, void *mlx, char *line)
{
	void	*file;
	int		i;
	char	c;
	int		size[2];

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	c = line[i];
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	file = mlx_xpm_file_to_image(mlx, &line[i], &size[0], &size[1]);
	if (!file || size[0] != 64 || size[1] != 64)
		return (print_error(1, line, 1));
	set_file(images, file, c);
	if (images->no != file && images->so != file
		&& images->ea != file && images->we != file)
	{
		mlx_destroy_image(mlx, file);
		return (print_error(2, line, -2));
	}
	return (0);
}
