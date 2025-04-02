#include "../cub3d.h"

int	max_x(t_point **row)
{
	int	x;

	x = 0;
	while (row[x])
		x++;
	return (x);
}

int max_y(t_point ***map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	can_access(int x, int y, t_point ***map)
{
	if (x < 0 || y < 0)
		return (0);
	if (max_y(map) <= y)
		return (0);
	if (max_x(map[y]) <= x)
		return (0);
	return (1);
}
