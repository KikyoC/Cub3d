#include "../cub3d.h"

static void	set_file(t_images *images, t_img *file, char c)
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
	t_img	*img;
	int		i;
	char	c;

	i = 0;
	img = malloc(sizeof(t_img));
	img->addr = NULL;
	img->img_ptr = NULL;
	while (ft_isspace(line[i]))
		i++;
	c = line[i];
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	img->img_ptr = mlx_xpm_file_to_image(mlx, &line[i], \
		&img->width, &img->height);
	if (!img->img_ptr || img->width != 64 || img->height != 64)
		return (print_error(1, line, 1));
	img->addr = mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->line_len, &img->endian);
	set_file(images, img, c);
	if (images->no != img && images->so != img
		&& images->ea != img && images->we != img)
	{
		mlx_destroy_image(mlx, img->img_ptr);
		return (print_error(2, line, -2));
	}
	return (0);
}
