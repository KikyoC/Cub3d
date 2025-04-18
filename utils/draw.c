/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:48:50 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/18 12:51:11 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_column(t_img *img, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < SQUARE)
	{
		mlx_put_pixel(img, x, y + i, color);
		i++;
	}
}

void	draw_square(t_img *img, int pos[2], int color)
{
	int	i;

	i = 0;
	while (i < SQUARE)
	{
		draw_column(img, pos[0] + i, pos[1], color);
		i++;
	}
}
