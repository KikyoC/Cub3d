#include "../cub3d.h"

int	set_number(int *res, char *str)
{
	int	i;

	i = -1;
	if (*str == ',')
		return (0);
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			return (-1);
		if (str[i] == ',')
			return (i + 1);
		*res *= 10;
		*res += str[i] - '0';
		if (*res > 255)
		{
			return (-1);
		}
	}
	return (i);
}

static int	parse_numbers(int *res, char *str, char *line)
{
	int	i;
	int	count;
	int	tmp;

	i = 0;
	count = 0;
	while (i < 3)
	{
		tmp = set_number(&res[i], &str[count]);
		if (tmp <= 0)
		{
			ft_putstr_fd("Error\nParse error near: \"", 2);
			ft_putstr_fd(&str[count], 2);
			ft_putstr_fd("\" on line \"", 2);
			ft_putstr_fd(line, 2);
			ft_putstr_fd("\"\n", 2);
			return (0);
		}
		count += tmp;
		i++;
	}
	return (1);
}

int	parse_color(t_images *images, char *line)
{
	int		i;
	char	c;
	int		*res;

	i = 0;
	res = ft_calloc(3, sizeof(int));
	while (ft_isspace(line[i]))
		i++;
	c = line[i];
	i++;
	while (ft_isspace(line[i]))
		i++;
	if (parse_numbers(res, &line[i], line))
	{
		if (c == 'C')
			images->sky = res;
		else if (c == 'F')
			images->ground = res;
		return (0);
	}
	free(res);
	return (1);
}

static int	get_rgb(int *color)
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

int build_background(t_game *game)
{
	int		x;
	int		y;

	if (!game || !game->images || !game->images->sky || !game->images->ground)
		return (1);
	game->images->background = ft_calloc(1, sizeof(t_img));
	if (!game->images->background)
		return (1);
	game->images->background->img_ptr = mlx_new_image(game->mlx_ptr, game->width, game->height);
	game->images->background->addr = mlx_get_data_addr(
		game->images->background->img_ptr, &game->images->background->bpp,
		&game->images->background->line_len, &game->images->background->endian);
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (y < game->height / 2)
				mlx_put_pixel(game->images->background, x, y, get_rgb(game->images->sky));
			else
				mlx_put_pixel(game->images->background, x, y, get_rgb(game->images->ground));
		}
	}
	return (0);
}
