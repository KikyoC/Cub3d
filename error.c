#include "cub3d.h"

/*If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message
of your choice*/

void	error_per(char *str, int flag)
{
	if(flag == 0)
		perror(str);
	exit(1);
}

void	error_msg(char *str, int flag)
{
	if(flag == 0)
		ft_putendl(str, 2);
	exit(1);
}