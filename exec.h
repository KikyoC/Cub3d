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

typedef struct s_camera{
	t_pos	pos;
	t_pos	dir;
	t_pos	x_dir;
	t_pos	plane;
} t_camera;


#endif