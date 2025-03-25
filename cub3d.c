#include "cub3d.h"

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

int	generate_rgb(__uint8_t red, __uint8_t green, __uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	paint_window(t_img *img, int x, int y, int color)
{
    char    *pixel;
    int		i;

    i = img->bpp - 8;
    pixel = img->adr + (y * img->line_len + x * (img->bpp / 8));
    while (i >= 0)
    {
        /* big endian, MSB is the leftmost bit */
        if (img->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        /* little endian, LSB is the leftmost bit */
        else
            *pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}
// #define PATH 

int	ft_rendermap(t_game *game)
{
	t_img img;
	int x = 0; 
	int y = 0;

	char *str = ft_strdup("wolftext/greystone.xpm");
	img.mlx_img = mlx_xpm_to_image(game->mlx_ptr, &str, &x, &y);
	__uint8_t red = 210;
	__uint8_t green = 120;
	__uint8_t blue = 0;
	int color = generate_rgb(red, green , blue);
	//permet de recuperer une image
	img.adr = mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_len, &img.endian);
	paint_window(&img, x, y, color);
	free(str);
	return(0);
}

void	ft_cub3d(char *str)
{
	(void) str;
	t_game game;

	ft_init_mlx(&game);
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, ft_keybind, &game);
	mlx_hook(game.win_ptr, Expose, ExposureMask, ft_rendermap, &game);
	mlx_hook(game.win_ptr, DestroyNotify, StructureNotifyMask, ft_closegame, &game);
	mlx_loop(game.mlx_ptr);
}

int	main(int ac, char **av)
{
	if(ac != 2)
		return (1);	//error_msg();
	if(ft_isitcub(av[1]) == 1)
		return (1); //error_msg();
	ft_cub3d(av[1]);
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
