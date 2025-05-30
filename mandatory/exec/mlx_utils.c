/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:04:34 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 10:29:49 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)dst = color;
}

int	*generate_color(int red, int green, int blue)
{
	int	*res;

	res = ft_calloc(1, sizeof(int));
	if (!res)
		return (NULL);
	*res = red << 16 | green << 8 | blue;
	return (res);
}
