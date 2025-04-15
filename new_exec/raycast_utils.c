#include "../cub3d.h"

void	cos_sin_handler(t_ray *ray)
{
	if (ray->cos == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->cos);
	if (ray->sin == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->sin);
	if (ray->cos < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->sin < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}
