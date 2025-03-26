#include "../cub3d.h"

int	generate_rgb(__uint8_t red, __uint8_t green, __uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
