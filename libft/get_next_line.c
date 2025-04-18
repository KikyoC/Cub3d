/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:40:04 by tom               #+#    #+#             */
/*   Updated: 2024/10/30 09:30:43 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	fillbuffer(int fd, char **buffer)
{
	*buffer = ft_calloc(21, sizeof(char));
	if (!*buffer)
		return (-10);
	return (read(fd, *buffer, 20));
}

char	*readfile(int fd, char *res)
{
	ssize_t	bytes;
	char	*buffer;
	char	*tmp;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = fillbuffer(fd, &buffer);
		if (bytes < 0)
		{
			if (bytes != -10)
				free(buffer);
			free(res);
			return (NULL);
		}
		tmp = ft_strdup(res);
		free(res);
		res = ft_strjoin(tmp, buffer);
		free(tmp);
		free(buffer);
		if (ft_strchr(res, '\n'))
			break ;
	}
	return (res);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!res)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[i + 1])
		res[j++] = buffer[i++ + 1];
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(21, sizeof(char));
	if (!buffer)
		return (NULL);
	buffer = readfile(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = update_buffer(buffer);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
