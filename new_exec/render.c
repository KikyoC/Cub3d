#include "../cub3d.h"
#include <sys/time.h>

void	edit_direction(t_player *player)
{
	if (player->l_move)
		player->direction -= 0.03;
	if (player->r_move)
		player->direction += 0.03;
}

void	move_player(t_game *game)
{
	float	p_cos;
	float	p_sin;
	
	p_cos = cos(game->player->direction);
	p_sin = sin(game->player->direction);
	if (game->player->w_move)
	{
		game->player->x += p_cos * 6;
		game->player->y += p_sin * 6;
	}
	if (game->player->s_move)
	{
		game->player->x -= p_cos * 6;
		game->player->y -= p_sin * 6;
	}
	if (game->player->a_move)
	{
		game->player->x -= p_cos * 6;
		game->player->y += p_sin * 6;
	}
	if (game->player->d_move)
	{
		game->player->x += p_cos * 6;
		game->player->y -= p_sin * 6;
	}
}

int	new_render()
{
	static struct timeval	old;
	struct timeval			current;
	if (old.tv_sec == 0)
	{
		gettimeofday(&old, NULL);
		return (1);
	}
	gettimeofday(&current, NULL);
	if (current.tv_sec * 1000 + current.tv_usec / 1000 > old.tv_sec * 1000 + old.tv_usec / 1000 + 37)
	{
		old = current;
		return (1);
	}
	return (0);
}

int	ft_render(t_game *game)
{
	if (new_render())
	{
		edit_direction(game->player);
		if (can_access(game->player->x / 64, game->player->y / 64, game->map)
			&& !is_wall(game->map, game->player->x, game->player->y))
			ft_raycast(game);
		move_player(game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->win_tex->img_ptr, 0, 0);
		//ft_screen_reset(game->win_tex, game->height);
		mlx_destroy_image(game->mlx_ptr, game->win_tex->img_ptr);
		free(game->win_tex);
		ft_init_add(game);
	}
	return (0);
}
