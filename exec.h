#ifndef EXEC_H
# define EXEC_H

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ESC  			0xff1b
# define KEY_LEFT  			0xff51
# define KEY_RIGHT 			0xff53

typedef struct s_pos{
	double x;
	double y;
} t_pos;

typedef struct s_color{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_ray
{
	float	incre_angle;
	float	angle;
	float	cos;
	float	sin;
	float	hfov;
	float	lim;
	int		precision;
}				t_ray;

int		mlx_pixel_get(t_img *data, int x, int y);
void	mlx_area_put(t_img *d, t_pos p, t_pos dim, int color);
void	mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_dist_color(int color, float dist);
t_color	create_rgb(int color);
int		generate_color(int red, int green, int blue);
int		ft_closegame(t_game *game);
void	ft_init_mlx(t_game *game);
int		ft_rendermap(t_game *game);
int		ft_keypress(int keysym, t_game *game);
int 	ft_keyrelease(int keysym, t_game *game);
void	ft_init_add(t_game *game);
void	init_ray(t_game *game);
void	ft_raycast(t_game *game);
void	ft_draw(t_game *game, int ray_count, float dist);
float	distance_to_wall(t_game *game, float ray_angle);
void	draw_texture(t_game *game, t_img *img, int ray_count, int wall_height);
t_img	*get_texture(t_game *game);
int		get_tex_color(t_game *game, t_img *img, int z);


#endif