#include "cub3d.h"

// void	move_up()
// {
// 	if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) 
// 		posX += dirX * moveSpeed;
// 	if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) 
// 		posY += dirY * moveSpeed;
// }

// void	move_down()
// {
// 	if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) 
// 		posX -= dirX * moveSpeed;
// 	if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) 
// 		posY -= dirY * moveSpeed;
// }

// void	move_left()
// {
// 	double oldDirX = dirX;
// 	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
// 	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);

// 	double oldPlaneX = planeX;
// 	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
// 	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
// }

// void	move_right()
// {
// 	double oldDirX = dirX;
// 	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
// 	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);

// 	double oldPlaneX = planeX;
// 	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
// 	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// }

// void	look_left()
// {
// 	double oldDirX = dirX;
// 	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
// 	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);

// 	double oldPlaneX = planeX;
// 	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
// 	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);	
// }

// void	look_right()
// {
// 	double oldDirX = dirX;
// 	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
// 	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);

// 	double oldPlaneX = planeX;
// 	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
// 	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// }

int	ft_keybind(int keysym, t_game *game)
{
	// if (keysym == KEY_W)
	// 	move_up();
	// if (keysym == KEY_A)
	// 	move_left();
	// if (keysym == KEY_D)
	// 	move_right();
	// if (keysym == KEY_S)
	// 	move_down();
	// if (keysym == KEY_LEFT)
	// 	look_left();
	// if (keysym == KEY_RIGHT)
	// 	look_right();
	if (keysym == KEY_ESC)
		ft_closegame(game);
	return (0);
}
