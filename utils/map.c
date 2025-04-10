#include "../cub3d.h"

int	is_wall(t_point ***map, double p_x, double p_y)
{
	int	x;
	int	y;

	x = p_x / 64;
	y = p_y / 64;
	if (!can_access(x, y, map))
		return (1);
	if (map[y][x]->c == '1')
		return (1);
	return (0);
}
