#include "cub3d.h"

int	generate_rgb(__uint8_t red, __uint8_t green, __uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_adr(t_img *img, int pixel, int color)
{
	int i = 0;
	while(i < 3850)
	{
		img->adr[pixel + i + 0] = (color) & 0xFF;
		img->adr[pixel + i + 1] = (color >> 8) & 0xFF;
		img->adr[pixel + i + 2] = (color >> 16) & 0xFF;
		img->adr[pixel + i + 3] = (color >> 24);
		i+=4;
	}
}

void	ft_addr(t_img *img, int pixel, int color)
{
	int i = 0;
	while(i < 32)
	{
		img->adr[pixel + i + 0] = (color >> 24);
		img->adr[pixel + i + 1] = (color >> 16) & 0xFF;
		img->adr[pixel + i + 2] = (color >> 8) & 0xFF;
		img->adr[pixel + i + 3] = (color) & 0xFF;
		i+=4;
	}
}

static void	generate_ceiling(t_img *img, int color)
{
	int x = 0;
	int y = 0;
	int pixel;

	while(x < 960 && y < 540 / 2) 
	{
		pixel = (y * img->line_len) + (x * 4);
		if(img->endian == 1)
		{
			ft_addr(img,pixel,color);
		}
		else if(img->endian == 0)
		{
			ft_adr(img, pixel, color);
		}
		++x;
		++y;
	}
	return ;
}

void	generate_floor(t_img *img, int color)
{
	int x = 0;
	int y = 540 / 2;
	int pixel;

	while(x < 960 && y < 540) 
	{
		pixel = (y * img->line_len) + (x * 4);
		if(img->endian == 1)
		{
			ft_addr(img,pixel,color);
		}
		else if(img->endian == 0)
		{
			ft_adr(img, pixel, color);
		}
		++x;
		++y;
	}
	return ;
}

void	ceiling_color(t_game *game)
{
	__uint8_t red = 210;
	__uint8_t green = 120;
	__uint8_t blue = 0;
	int color = generate_rgb(red, green, blue);
	color = mlx_get_color_value(game->mlx_ptr, color);
	game->ceiling.mlx_img = mlx_new_image(game->mlx_ptr, 960, 540);
	game->ceiling.adr = mlx_get_data_addr(game->ceiling.mlx_img, &game->ceiling.bpp, &game->ceiling.line_len, &game->ceiling.endian);
	generate_ceiling(&game->ceiling, color);
	red = 120;
	green = 200;
	blue = 0;
	color = generate_rgb(red, green, blue);
	generate_floor(&game->ceiling, color);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->ceiling.mlx_img, 0, 0);
}
