#ifndef CUB3D_H
# define CUB3D_H

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ESC  			0xff1b
# define KEY_LEFT  			0xff51
# define KEY_RIGHT 			0xff53

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx_linux/mlx.h"
# include "libft/libft.h"

//Map
typedef struct s_img{
	void	*mlx_img;
	char 	*adr;
	int bpp;
	int line_len;
	int endian;
} t_img;

typedef struct s_game {
	void		*mlx_ptr;
	void		*win_ptr;
	t_img 		img;
    int	config;
    int	no;
    int	so;
    int	ea;
    int	we;
}    t_game;

typedef struct s_point {
    char            *c;
    struct s_point    *next;
}    t_point;

typedef struct s_row {
    struct s_point    *first;
    struct s_row    *next;
}    t_row;

int		ft_closegame(t_game *game);
int		ft_keybind(int keysym, t_game *game);
void	error_msg(char *str, t_game *game, int flag);
void	error_per(char *str, t_game *game, int flag);
void	ft_init_mlx(t_game *game);

#endif