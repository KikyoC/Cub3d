#include "cub3d.h"

int	ft_test(char *str, int i)
{
	str[i] = '\0';
	i = ft_atoi(str);
	printf("%d\n", i);
	return (i);
}

void	ft_tttt(char *str)
{
	int	i = 0;
	int	occ = 0;
	while(occ != 3 && str[i])
	{
		if(occ != 3 && ft_isdigit(str[i]))
		{
			str = &str[i];
			i = 0;
			while(str[i] && str[i] != ',')
				i++;
			ft_test(str, i);
			occ++;
			i++;
		}
		else
			i++;
	}
}

int	main(void)
{
	char *str = ft_strdup("F 255,240,128");
	ft_tttt(str);
	free(str);
}
