/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:39 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/16 13:00:54 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_number(int *res, char *str)
{
	int	i;

	i = -1;
	if (*str == ',')
		i = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			return (-1);
		if (str[i] == ',')
			return (i);
		*res *= 10;
		*res += str[i] - '0';
		if (*res > 255)
			return (-1);
	}
	return (i);
}

static int	parse_numbers(int *res, char *str, char *line)
{
	int	i;
	int	count;
	int	tmp;

	i = 0;
	count = 0;
	while (str[count])
	{
		tmp = set_number(&res[i], &str[count]);
		if (tmp <= 0 || i >= 3)
		{
			ft_putstr_fd("Error\nParse error near: \"", 2);
			ft_putstr_fd(&str[count], 2);
			ft_putstr_fd("\" on line \"", 2);
			ft_putstr_fd(line, 2);
			ft_putstr_fd("\"\n", 2);
			return (0);
		}
		count += tmp;
		while (ft_isspace(str[count]))
			count++;
		i++;
	}
	return (1);
}

static void	init(char *line, int *i, char *c)
{
	while (ft_isspace(line[*i]))
		(*i)++;
	*c = line[*i];
	(*i)++;
	while (ft_isspace(line[*i]))
		(*i)++;
}

int	parse_color(t_images *images, char *line)
{
	int		i;
	char	c;
	int		*res;

	res = ft_calloc(4, sizeof(int));
	if (!res)
		return (1);
	i = 0;
	init(line, &i, &c);
	if (parse_numbers(res, &line[i], line))
	{
		if (c == 'C' && images->sky == 0)
			images->sky = generate_color(res[0], res[1], res[2]);
		else if (c == 'F' && images->ground == 0)
			images->ground = generate_color(res[0], res[1], res[2]);
		else
		{
			free(res);
			return (1);
		}
		free(res);
		return (0);
	}
	free(res);
	return (1);
}
