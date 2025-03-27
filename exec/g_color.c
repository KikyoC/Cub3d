#include "../cub3d.h"

int	generate_color(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

t_color	create_rgb(int color)
{
	t_color	c;

	c.red = (color >> 16) & 0xFF;
	c.green = (color >> 8) & 0xFF;
	c.blue = color & 0xFF;
	return (c);
}

int	get_dist_color(int color, float dist)
{
	t_color	c;
	float	dif;

	if (dist < 0)
		dist = 0;
	dif = powf(1.14, dist / 7.5);
	c = create_rgb(color);
	c.red -= dif;
	c.green -= dif;
	c.blue -= dif;
	if (c.red < 0)
		c.red = 0;
	if (c.green < 0)
		c.green = 0;
	if (c.blue < 0)
		c.blue = 0;
	return (generate_color(c.red, c.green, c.blue));
}
