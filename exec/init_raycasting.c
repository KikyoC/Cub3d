#include "../cub3d.h"

float	degree_to_radians(float degree)
{
	return (degree * M_PI / 180);
}

// float	distance_to_wall(t_game *game, float ray_angle)
// {
// 	float	dir;

// 	game->ray.cos = cos(degree_to_radians(ray_angle)) / game->ray.precision;
// 	game->ray.sin = sin(degree_to_radians(ray_angle)) / game->ray.precision;
// 	game->x = game->player->x + 0.5;
// 	game->y = game->player->y + 0.5;
// 	while (can_access(game->x, game->y, game->map) && \
// 		!ft_strchr("1", game->map[(int)game->y][(int)game->x]->c) && \
// 		sqrt(powf(game->x - game->player->x - 0.5, 2.) + \
// 		powf(game->y - game->player->y - 0.5, 2.)) < game->ray.lim)
// 	{
// 		game->x += game->ray.cos;
// 		game->y += game->ray.sin;
// 	}
// 	dir = sqrt(powf(game->x - game->player->x - 0.5, 2.) + powf(game->y - game->player->y - 0.5, 2.));
// 	return (dir * cos(degree_to_radians(ray_angle - game->ray.angle)));
// }

// Replace your current distance_to_wall function with this implementation

double distance_to_wall(t_game *game, double ray_angle)
{
    // Ray direction vector
    double ray_dir_x = cos(degree_to_radians(ray_angle));
    double ray_dir_y = sin(degree_to_radians(ray_angle));
    
    // Player position (cell coordinates)
    int map_x = (int)game->player->x;
    int map_y = (int)game->player->y;
    
    // Length of ray from current position to next x or y-side
    double side_dist_x;
    double side_dist_y;
    
    // Length of ray from one x or y-side to next x or y-side
    double delta_dist_x = fabs(1 / ray_dir_x);
    double delta_dist_y = fabs(1 / ray_dir_y);
    
    // What direction to step in x or y direction (either +1 or -1)
    int step_x;
    int step_y;
    
    // Calculate step and initial side_dist
    if (ray_dir_x < 0)
    {
        step_x = -1;
        side_dist_x = (game->player->x - map_x) * delta_dist_x;
    }
    else
    {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - game->player->x) * delta_dist_x;
    }
    
    if (ray_dir_y < 0)
    {
        step_y = -1;
        side_dist_y = (game->player->y - map_y) * delta_dist_y;
    }
    else
    {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - game->player->y) * delta_dist_y;
    }
    
    int hit = 0;  // Was a wall hit?
    int side;     // Was a NS or EW wall hit?
    
    // Perform DDA
    while (hit == 0)
    {
        // Jump to next map square, either in x-direction, or in y-direction
        if (side_dist_x < side_dist_y)
        {
            side_dist_x += delta_dist_x;
            map_x += step_x;
            side = 0;
        }
        else
        {
            side_dist_y += delta_dist_y;
            map_y += step_y;
            side = 1;
        }
        
        // Check if ray has hit a wall
        if (map_y < 0 || map_x < 0 || map_y >= game->map_height || map_x >= game->map_width)
            break;  // Out of bounds
        
        if (ft_strchr("1", game->map[map_y][map_x]->c))
            hit = 1;
    }
    
    // Calculate distance projected on camera direction
    double perp_wall_dist;
    if (side == 0)
        perp_wall_dist = (map_x - game->player->x + (1 - step_x) / 2) / ray_dir_x;
    else
        perp_wall_dist = (map_y - game->player->y + (1 - step_y) / 2) / ray_dir_y;
    
    // Store hit position for texturing
    game->x = map_x;
    game->y = map_y;
    
    return perp_wall_dist;
}

void	ft_draw(t_game *game, int ray_count, float dist)
{
	int		wall_height;
	float	d;
	int		j;
	int ground;
	int sky;

	wall_height = (int)(game->height / (1.5 * dist));
	d = ((float)game->height / 2) - (float)wall_height;
	j = -1;
	sky = generate_color(game->images->sky[0], game->images->sky[1], game->images->sky[2]);
	ground = generate_color(game->images->ground[0], game->images->ground[1], game->images->ground[2]);
	while (++j < game->height)
	{
		if (j < d)
			mlx_put_pixel(&game->win_tex, ray_count, j,
				get_dist_color(sky, j));
		else if (j >= (game->height / 2) + wall_height)
			mlx_put_pixel(&game->win_tex, ray_count, j,
				get_dist_color(ground, game->height - j));
	}
	draw_texture(game, get_texture(game), ray_count, wall_height);
}

void	ft_raycast(t_game *game)
{
	float	dist;
	float	ray_angle;
	int		ray_count;

	ray_angle = game->ray.angle - game->ray.hfov;
	ray_count = -1;
	while (++ray_count < game->width)
	{
		dist = distance_to_wall(game, ray_angle);
		ft_draw(game, ray_count, dist);
		ray_angle += game->ray.incre_angle;
	}
}

void	ft_init_ray(t_game *game)
{
	game->ray.angle = game->player->direction;
	game->ray.hfov = 30;
	game->ray.incre_angle = 2 * game->ray.hfov / game->width;
	game->ray.precision = 150;
	game->ray.lim = 11;
}
