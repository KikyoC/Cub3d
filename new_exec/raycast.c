#include "../cub3d.h"

void	cos_sin_handler(t_ray *ray)
{
	if (ray->cos == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->cos);
	if (ray->sin == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->sin);
	if (ray->cos < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->sin < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

t_ray	create_ray(t_game *game, double start_x)
{
	t_ray	ray;

	ray.ray_x = game->player->x;
	ray.ray_y = game->player->y;
	ray.cos = cos(start_x);
	ray.sin = sin(start_x);
	ray.map_x = (int)(ray.ray_x / 64);
	ray.map_y = (int)(ray.ray_y / 64);
	cos_sin_handler(&ray);
	if (ray.cos < 0)
		ray.side_dist_x = (ray.ray_x / 64 - ray.map_x) * ray.delta_dist_x;
	else
		ray.side_dist_x = (ray.map_x + 1.0 - ray.ray_x / 64) * ray.delta_dist_x;
	if (ray.sin < 0)
		ray.side_dist_y = (ray.ray_y / 64 - ray.map_y) * ray.delta_dist_y;
	else
		ray.side_dist_y = (ray.map_y + 1.0 - ray.ray_y / 64) * ray.delta_dist_y;
	return (ray);
}

t_ray	perform_dda(t_game *game, t_ray ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray.side_dist_x < ray.side_dist_y)
		{
			ray.side_dist_x += ray.delta_dist_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_dist_y += ray.delta_dist_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (!can_access(ray.map_x, ray.map_y, game->map)
			|| game->map[(int)ray.map_y][(int)ray.map_x]->c == '1')
			hit = 1;
	}
	return (ray);
}

t_img	*get_texture(t_game *game, t_ray ray)
{
	t_img	*img;
	float	ray_cos;
	float	ray_sin;

	img = NULL;
	ray_cos = fabs(ray.cos);
	ray_sin = fabs(ray.sin);
	if (can_access(ray.map_x, ray.map_y - ray_sin, game->map) && \
	game->map[(int)(ray.map_y - ray_sin)][(int)ray.map_x]->c != '1')
		img = game->images->no;
	else if (can_access(ray.map_x, ray.map_y + ray_sin, game->map) && \
		game->map[(int)(ray.map_y + ray_sin)][(int)ray.map_x]->c != '1')
		img = game->images->so;
	else if (can_access(ray.map_x + ray_cos, ray.map_y, game->map) && \
		game->map[(int)ray.map_y][(int)(ray.map_x + ray_cos)]->c != '1')
		img = game->images->ea;
	else if (can_access(ray.map_x - ray_cos, ray.map_y, game->map) && \
		game->map[(int)ray.map_y][(int)(ray.map_x - ray_cos)]->c != '1')
		img = game->images->we;
	return (img);
}

int	get_tex_color(t_game *game, t_img *img, t_ray ray, int z)
{
	int	color;

	color = 0x00000000;
	if (game->map[(int)ray.map_y][(int)ray.map_x]->c == '1')
		color = mlx_pixel_get(img, (int)(img->width * (ray.map_x + ray.map_y)) \
			% img->width, z);
	return (color);
}

typedef struct s_color{
	int red;
	int green;
	int blue;
} t_color;

t_color	create_rgb(int color)
{
	t_color	c;

	c.red = (color >> 16) & 0xFF;
	c.green = (color >> 8) & 0xFF;
	c.blue = color & 0xFF;
	return (c);
}

int	get_dist_color(int color, float dist)
{
	t_color	c;
	float	dif;

	if (dist < 0)
		dist = 0;
	dif = powf(1.14, dist / 7.5);
	c = create_rgb(color);
	c.red -= dif;
	c.green -= dif;
	c.blue -= dif;
	if (c.red < 0)
		c.red = 0;
	if (c.green < 0)
		c.green = 0;
	if (c.blue < 0)
		c.blue = 0;
	return (generate_color(c.red, c.green, c.blue));
}

static void	draw_verticality(float *cy, t_game *game, int ray_count, int color)
{
	while (cy[0] < cy[1])
	{
		if (cy[0] >= 0 && cy[0] < (float)game->height)
			mlx_put_pixel(game->win_tex, ray_count, cy[0], color);
		cy[0]++;
		if (cy[0] < -500 || cy[0] > (float)game->height + 300)
			break ;
	}
}

void	draw_texture(t_game *game, t_ray ray, int ray_count, double wall_height)
{
	float	dy;
	float	dist;
	float	cy[2];
	t_img	*img;
	int		z;
	int		color;

	img = get_texture(game, ray);
	if (!img)
		return ;
	dy = ((float)wall_height * 2) / (float)img->height;
	dist = ((float)game->height / 2) - (float)wall_height;
	cy[1] = dist;
	z = -1;
	while (++z < img->height)
	{
		color = get_tex_color(game, img, ray, z);
		color = get_dist_color(color, dist);
		cy[0] = cy[1];
		cy[1] += dy;
		draw_verticality(cy, game, ray_count, color);
	}
}

void	draw(t_game *game, t_ray ray, int count)
{
	double	distance;
	double	height;
	int		start_y;
	int		z;
	int		end;

	z = 0;
	distance = get_distance(game, ray);
	height = (64 / distance) * ((double)game->width / 2);
	start_y = (game->height - height) / 2;
	end = start_y + height;
	while (z < game->height)
	{
		if (z < start_y)
			mlx_put_pixel(game->win_tex, count, z, generate_color(0, 0, 255));
		else if (z >= start_y && z < end)
			draw_texture(game, ray, count, height);
		else
			mlx_put_pixel(game->win_tex, count, z, generate_color(0, 255, 0));
		z++;
	}
}

void	ft_raycast(t_game *game)
{
	t_ray		ray;
	int			count;
	double		start_x;
	double		fraction;
	//static int	print;

	count = 0;
	fraction = M_PI / 3 / game->width;
	start_x = game->player->direction - M_PI / 6;
	while (count < game->width)
	{
		ray = create_ray(game, start_x);
		ray = perform_dda(game, ray);
		draw(game, ray, count);
		start_x += fraction;
		count ++;
	}
	//print = 1;
}
