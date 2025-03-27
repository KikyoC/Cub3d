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
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"
# include <errno.h>
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "X11/X.h"

# define S_TEXTURE "Error\nIt seems that you didn't set up south texture\n"
# define N_TEXTURE "Error\nIt seems that you didn't set up north texture\n"
# define E_TEXTURE "Error\nIt seems that you didn't set up east texture\n"
# define W_TEXTURE "Error\nIt seems that you didn't set up west texture\n"
# define GROUND "Error\nIt seems that you didn't set up ground color\n"
# define SKY "Error\nIt seems that you didn't set up sky color\n"
# define MAP "Error\nIt seems that you didn't set up map\n"
# define POS "Error\nI don't know where the player starts\n"

/*
	* STRUCTS
*/
typedef struct s_game
{
	int				config;
	void			*mlx_ptr;
	void			*win_ptr;
	struct s_point	***map;
	struct s_images	*images;
	struct s_player	*player;
}	t_game;

typedef struct s_images
{
	void			*no;
	void			*so;
	void			*ea;
	void			*we;
	int				*ground;
	int				*sky;
}	t_images;

//Map

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

typedef struct s_player
{
	struct s_point	*point;
	float			x;
	float			y;
	float			direction;
}	t_player;

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
