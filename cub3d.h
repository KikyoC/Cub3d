/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:05:21 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 14:01:00 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <errno.h>
# include <sys/time.h>
# include "libft/libft.h"
# include "mlx_linux/mlx.h"

/*
	* Errors
*/
# define S_TEXTURE "Error\nIt seems that you didn't set up south texture\n"
# define N_TEXTURE "Error\nIt seems that you didn't set up north texture\n"
# define E_TEXTURE "Error\nIt seems that you didn't set up east texture\n"
# define W_TEXTURE "Error\nIt seems that you didn't set up west texture\n"
# define GROUND "Error\nIt seems that you didn't set up ground color\n"
# define SKY "Error\nIt seems that you didn't set up sky color\n"
# define MAP "Error\nIt seems that you didn't set up map\n"
# define POS "Error\nI don't know where the player starts\n"
# define EXTENSION "cub"

/*
	* MLX keys
 * */

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100
# define KEY_ESC  			0xff1b
# define KEY_LEFT  			0xff51
# define KEY_RIGHT 			0xff53

# define M_PI 3.14159265358979323846

/*
	* STRUCTURE
*/

typedef struct s_img
{
	int		height;
	int		width;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_images
{
	t_img			*no;
	t_img			*so;
	t_img			*ea;
	t_img			*we;
	int				*ground;
	int				*sky;
}	t_images;

typedef struct s_player
{
	double			x;
	double			y;
	double			direction;
	int				w_move;
	int				s_move;
	int				a_move;
	int				d_move;
	int				l_move;
	int				r_move;
	struct s_point	*point;
}	t_player;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				config;
	int				height;
	int				width;
	t_img			*win_tex;
	t_player		*player;
	struct s_point	***map;
	struct s_images	*images;
}	t_game;

typedef struct s_point
{
	char			c;
}	t_point;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	double	cos;
	double	sin;
	int		step_x;
	int		step_y;
	int		side;
	double	ray_x;
	double	ray_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	p_wall;
	double	distance;
}	t_ray;

/*
	* FUNCTIONS
*/

int		parse_color(t_images *images, char *line);
int		open_texture(t_images *images, void *mlx, char *line);
int		parse_line(t_game *game, char *line, int *map);
int		is_map_valid(t_game *game);
int		destroy(t_game *game, int to_return);
void	destroy_row(t_point **row);
int		parse(t_game *game, char *filename);
int		setup_player(t_game *game);
int		get_line_type(char *line);
int		get_row_size(char *file_name);
void	mlx_put_pixel(t_img *img, int x, int y, int color);
void	cos_sin_handler(t_ray *ray);
int		*generate_color(int red, int green, int blue);
void	ft_init_mlx(t_game *game);
int		ft_render(t_game *game);
int		ft_press(int keysym, t_game *game);
int		ft_release(int keysym, t_player *player);
void	ft_init_add(t_game *game);
void	ft_raycast(t_game *game);
int		can_access(int x, int y, t_point ***map);
int		is_wall(t_point ***map, double p_x, double p_y);
double	get_distance(t_game *game, t_ray ray);
int		is_point_valid(t_point ***map, int x, int y);
int		get_line_type(char *line);
void	destroy_row(t_point **row);
int		get_good_pixel(t_img *img, double x, double z, int wall_height);
t_img	*get_good_img(t_ray ray, t_game *game);
void	set_touch(t_game *game, t_ray *ray);
t_ray	create_ray(t_game *game, double start_x);
t_ray	perform_dda(t_game *game, t_ray ray);
double	get_angle(double direction, int key);

#endif
