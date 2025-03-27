#include "../cub3d.h"

int	get_row_size(char *file_name)
{
	int		config;
	int		res;
	char	*line;

	res = 0;
	config = open(file_name, O_RDONLY);
	if (config < 0)
		return (-1);
	line = get_next_line(config);
	while (line)
	{
		if (get_line_type(line) == 3)
			res++;
		free(line);
		line = get_next_line(config);
	}
	close(config);
	return (res);
}
