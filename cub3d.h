#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
//# include "../mlx_linux/mlx.h"
# include "libft/libft.h"
# include <errno.h>

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
	int				no;
	int				so;
	int				ea;
	int				we;
	int				*ground;
	int				*sky;
	struct s_row	*first;
}	t_game;

//Map

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

/*
	* FUNCTIONS
*/

int		parse_color(t_game *game, char *line);
int		open_texture(t_game *game, char *line);
int		parse_line(t_game *game, char *line);
int		is_map_valid(t_game *game);
int		destroy(t_game *game, int to_return);
void	destroy_row(t_row *row);
#endif
