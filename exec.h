#ifndef EXEC_H
# define EXEC_H

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ESC  			0xff1b
# define KEY_LEFT  			0xff51
# define KEY_RIGHT 			0xff53

# define M_PI 3.14159265358979323846

typedef struct s_pos
{
	double	x;
	double	y;
}	t_pos;

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_ray
{
	double	map_x;
	double	map_y;
	double	x_e;
	double	y_e;
	double	cos;
	double	sin;
	int		step_x;
	int		step_y;
	double	delta_x;
	double	delta_y;
	int		side;
	//float	side_x;
	//float	side_y;
	float	ray_x;
	float	ray_y;
	double	side_dist_x; 
	double	side_dist_y;
	double	delta_dist_x; 
	double	delta_dist_y;
}	t_ray;

#endif
