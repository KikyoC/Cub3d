/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huvillat <huvillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:05:11 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 16:01:11 by huvillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_file(t_images *images, t_texture *file, char c)
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

static int	print_error(int type, char *line, int to_return, void *free_me)
{
	if (free_me)
		free(free_me);
	if (type == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd(" on line \"", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\"\n", 2);
	}
	else if (type == 2)
	{
		ft_putstr_fd("Error\nDuplicated texture on line \"", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\"\n", 2);
	}
	else
	{
		ft_putstr_fd("Error\nTexture \"", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\" must be 64 by 64 pixels\n", 2);
	}
	return (to_return);
}

int	open_file(t_texture *img, int i, char *line, void *mlx)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx, &line[i], &img->width,
			&img->height);
	if (!img->img_ptr)
		return (print_error(1, line, 1, img));
	if (img->height != 64 || img->width != 64)
	{
		mlx_destroy_image(mlx, img->img_ptr);
		return (print_error(3, line, 1, img));
	}
	img->addr = mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->line_len, &img->endian);
	return (0);
}

int	open_texture(t_images *images, void *mlx, char *line)
{
	t_texture	*img;
	int		i;
	char	c;

	i = 0;
	img = ft_calloc(1, sizeof(t_texture));
	while (ft_isspace(line[i]))
		i++;
	c = line[i];
	i += 2;
	while (ft_isspace(line[i]))
		i++;
	if (open_file(img, i, line, mlx))
		return (1);
	set_file(images, img, c);
	if (images->no != img && images->so != img
		&& images->ea != img && images->we != img)
	{
		mlx_destroy_image(mlx, img->img_ptr);
		return (print_error(2, line, -2, img));
	}
	return (0);
}
