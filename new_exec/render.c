#include "../cub3d.h"

void	edit_direction(t_player *player)
{
	if (player->l_move)
		player->direction -= 0.06;
	if (player->r_move)
		player->direction += 0.06;
}

void	move_player(double *x, double *y, double direction, int key)
{
	double	angle;

	angle = direction;
	if (key == KEY_S)
		angle += M_PI;
	else if (key == KEY_A)
		angle -= 0.5 * M_PI;
	else if (key == KEY_D)
		angle += 0.5 * M_PI;
	*x += cos(angle) * 6;
	*y += sin(angle) * 6;
}

int	new_render(void)
{
	static struct timeval	old;
	struct timeval			current;

	if (old.tv_sec == 0)
	{
		gettimeofday(&old, NULL);
		return (1);
	}
	gettimeofday(&current, NULL);
	if (current.tv_sec * 1000 + current.tv_usec / 1000
		> old.tv_sec * 1000 + old.tv_usec / 1000 + 37)
	{
		old = current;
		return (1);
	}
	return (0);
}

void	check_move(t_player *player)
{
	if (player->w_move)
		move_player(&player->x, &player->y, player->direction, KEY_W);
	if (player->a_move)
		move_player(&player->x, &player->y, player->direction, KEY_A);
	if (player->s_move)
		move_player(&player->x, &player->y, player->direction, KEY_S);
	if (player->d_move)
		move_player(&player->x, &player->y, player->direction, KEY_D);
}

int	ft_render(t_game *game)
{
	if (new_render())
	{
		edit_direction(game->player);
		if (can_access(game->player->x / 64, game->player->y / 64, game->map)
			&& !is_wall(game->map, game->player->x, game->player->y))
			ft_raycast(game);
		check_move(game->player);
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->win_tex->img_ptr, 0, 0);
		mlx_destroy_image(game->mlx_ptr, game->win_tex->img_ptr);
		free(game->win_tex);
		ft_init_add(game);
	}
	return (0);
}

void	put_ray(t_ray ray, int x, int y, t_game *game)
{
	int	i;
	int	j;

	mlx_put_pixel(game->win_tex, x, y, generate_color(255, 255, 255));
	return;
	(void)ray;
	i = y - 1;
	while (i < y + 2)
	{
		j = x - 1;
		while (j < x + 2)
		{
			mlx_put_pixel(game->win_tex, j, i, generate_color(255, 0, 0));
			j++;
		}
		i++;
	}
}
