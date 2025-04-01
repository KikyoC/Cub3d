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
	//printf("Trying to see %i %i\n", x, y);
	if (max_y(map) <= y)
	{
	//	printf("Nope\n");
		return (0);
	}
	if (max_x(map[y]) <= x)
	{
	//	printf("Nope\n");
		return (0);
	}
	//printf("Uwu\n");
	return (1);
}
