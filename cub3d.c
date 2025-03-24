#include "cub3d.h"

int	ft_isitcub(char *str)
{
	int	i;
	int j;
	char cub[3] = "cub";

	i = 0;
	j = -1;
	while(str[i])
	{
		if(str[i] == '.')
		{
			i++;
			while(str[i] && str[i] == cub[++j])
				++i;
			if(j != 2)
				return (1);
		}
		else
			i++;
	}
	if(j == 2 && str[i - 4] == '.')
		return (0);
	else
		return (1);
}

int	main(int ac, char **av)
{
	if(ac != 2)
		return (1);	//error_msg();
	if(ft_isitcub(av[1]) == 1)
		return (1); //error_msg();
	ft_cub3d(av[1]); //fonction principale
}