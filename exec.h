#ifndef EXEC_H
# define EXEC_H

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ESC  			0xff1b
# define KEY_LEFT  			0xff51
# define KEY_RIGHT 			0xff53

typedef struct s_move{
	
}	t_move;

typedef struct s_pos{
	double x;
	double y;
} t_pos;

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

typedef struct s_player{
	float	x;
	float	y;
	int w_move;
	int s_move;
	int a_move;
	int d_move;
	int l_move;
	int r_move;
	char	dir;
}	t_player;

typedef struct s_camera{
	t_pos	pos;
	t_pos	dir;
	t_pos	x_dir;
	t_pos	plane;
} t_camera;


#endif