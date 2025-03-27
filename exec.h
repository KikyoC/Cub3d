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

#endif