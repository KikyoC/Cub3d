#include "../cub3d.h"

int	get_line_type(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (((line[i] == 'N' && line[i + 1] == 'O')
			|| (line[i] == 'S' && line[i + 1] == 'O')
			|| (line[i] == 'W' && line[i + 1] == 'E')
			|| (line[i] == 'E' && line[i + 1] == 'A'))
		&& ft_isspace(line[i + 2]))
		return (1);
	else if ((line[i] == 'C' || line[i] == 'F') && ft_isspace(line[i + 1]))
		return (2);
	else if (line[i] == '\0' || line[i] == '\n')
		return (4);
	else
		return (3);
}
