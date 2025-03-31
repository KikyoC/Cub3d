#include "../cub3d.h"

void	add_img_to_img(int x_start, int y_start, t_img *src, t_img *to_copy, int height, int angle)
{
	int	x;
	int	y;

	y = 0;
	while (y < 64 * height)
	{
		x = 0;
		while (x < 64 * angle)
		{
			mlx_put_pixel(src, x + x_start, y + y_start, mlx_pixel_get(to_copy, x / angle, y / height));
			x++;
		}
		y++;
	}
}

t_img	*build_image(t_game *game)
{
	t_img	*img;
	
	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img = ft_memcpy(img, game->images->background, sizeof(t_img));
	add_img_to_img(10, 10, img, &game->win_tex, 8, 6);
	return (img);
}

int	ft_rendermap(t_game *game)
{
	t_img	*img;
	img = build_image(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_ptr, 0, 0);
	
	free(img);
	return (0);
}
