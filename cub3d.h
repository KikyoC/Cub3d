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
# include "libft/libft.h"
# include "exec.h"
# include <errno.h>
# include "mlx_linux/mlx.h"

# define S_TEXTURE "Error\nIt seems that you didn't set up south texture\n"
# define N_TEXTURE "Error\nIt seems that you didn't set up north texture\n"
# define E_TEXTURE "Error\nIt seems that you didn't set up east texture\n"
# define W_TEXTURE "Error\nIt seems that you didn't set up west texture\n"
# define GROUND "Error\nIt seems that you didn't set up ground color\n"
# define SKY "Error\nIt seems that you didn't set up sky color\n"
# define MAP "Error\nIt seems that you didn't set up map\n"
# define POS "Error\nI don't know where the player starts\n"

/*
	* STRUCTURE
*/

typedef struct s_img{
	int		height;
	int		width;
	void	*img_ptr;
	char 	*addr;
	int 	bpp;
	int 	line_len;
	int		endian;
} t_img;

typedef struct s_images
{
	void			*no;
	void			*so;
	void			*ea;
	void			*we;
	int				*ground;
	int				*sky;
}	t_images;

typedef struct s_player{
	float	x;
	float	y;
	int w_move;
	int s_move;
	int a_move;
	int d_move;
	int l_move;
	int r_move;
	struct s_point	*point;
}	t_player;

typedef struct s_game {
	void			*mlx_ptr;
	void			*win_ptr;
  int     config;
	int			height;
	int			width;
	float		x;
	float		y;
	t_img		win_tex;
	t_img		win_g;
	t_img 		win_c;
	t_ray 		ray;
	t_player	play;
	struct s_row	*first;
	struct s_images	*images;
}    t_game;

typedef struct s_point
{
	char			c;
	//struct s_row	*row;
	//struct s_point	*next;
	//struct s_point	*prev;
}	t_point;

//typedef struct s_row
//{
//	struct s_point	*first;
//	struct s_row	*next;
//	struct s_row	*prev;
//}	t_row;

/*
	* FUNCTIONS
*/

int		parse_color(t_images *images, char *line);
int		open_texture(t_images *images, void *mlx ,char *line);
int		parse_line(t_game *game, char *line);
int		is_map_valid(t_game *game);
int		destroy(t_game *game, int to_return);
void	destroy_row(t_point **row);
void	ft_init_mlx(t_game *game);
int		ft_keybind(int keysym, t_game *game);
void	ft_closegame(t_game *game);
int		parse(t_game *game, char *filename);
int		setup_player(t_game *game);
int		get_line_type(char *line);
int		get_row_size(char *file_name);

#endif
