#include "../cub3d.h"
#include <sys/time.h>

int new_render()
{
	static struct timeval	tv;
	struct timeval			current;
	int						res;

	gettimeofday(&current, NULL);
	if (tv.tv_sec == 0)
	{
		tv = current;
		return (1);
	}
	if ((current.tv_sec * 1000 + current.tv_usec / 1000) > (tv.tv_sec * 1000 + tv.tv_usec / 1000) + 17)
	{
		res = 1;
		tv = current;
	}
	else
		res = 0;
	return (res);
}

int	ft_rendermap(t_game *game)
{
	// int i = 0;

	// if(i == 0)
	// {
	if (new_render())
	{
		check_move(game);
		ft_raycast(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->win_tex.img_ptr, 0, 0);
	}
	return (0);
}
