#ifndef CUB3D_H
# define CUB3D_H

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
# include "exec.h"

//Map
typedef struct s_img{
	int		height;
	int		width;
	void	*img_ptr;
	char 	*addr;
	int 	bpp;
	int 	line_len;
	int		endian;
} t_img;

typedef struct s_data{
	void	*mlx_ptr;
	void	*win_ptr;
	int		config;
    int		no;
    int		so;
    int		ea;
    int		we;
}	t_data;

typedef struct s_game {
	int			height;
	int			width;
	t_img		win_tex;
	t_img		win_g;
	t_img 		win_c;
	t_ray 		ray;
	t_player	play;
}    t_game;

typedef struct s_point
{
	char			c;
	struct s_row	*row;
	struct s_point	*next;
	struct s_point	*prev;
}	t_point;

typedef struct s_row
{
	struct s_point	*first;
	struct s_row	*next;
	struct s_row	*prev;
}	t_row;

int		ft_closegame(t_game *game);
void	error_msg(char *str, t_game *game, int flag);
void	error_per(char *str, t_game *game, int flag);
void	ft_init_mlx(t_game *game);
int		ft_rendermap(t_game *game);
int		ft_keypress(int keysym, t_game *game);
int 	ft_keyrelease(int keysym, t_game *game);

#endif